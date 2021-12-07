#include "stm32l475xx.h"
#include "stm32l4xx_it.h"
#include <stdint.h>

void delay(uint32_t itiration); //delay function
__IO uint32_t count;
void SysTick_Initialize(void);
#define SYS_CLOCK_HZ 4000u //4000000 Default clock after startup, Divide by 1000 to get 1 millisecond(4000000/1000)


int main()
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;        //Enable RCC clock for portB, Writing 1 to bit1 of RCC_AHB2ENR register
    
    //Enable Pin14 to output mode
    //Write 01 to Mode register GPIOB_MODER
    GPIOB->MODER |= GPIO_MODER_MODER14_0;
    GPIOB->MODER &= ~GPIO_MODER_MODER14_1;

    SysTick_Initialize();

    while(1)
   {
      delay(1000);
      GPIOB->ODR ^= GPIO_ODR_OD14;      //Toggle the LED by Writing to output date register GPIOB_ODR
   }    
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk; // 0xE000E010 - Enable interrupts
}
void delay(__IO uint32_t time)
{
    count = time;
    while(count!=0);
}

void SysTick_Handler(void)
{
     if(count!=0)
     {
       count--;
     }
}
