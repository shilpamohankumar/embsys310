#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

// ************ Using CMSIS ************ //
#if 1
volatile int counter=0;

void main(void)
{   
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[0] to 1 to enable clock for GPIO port A
    // Enable clock to Peripheral
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;   
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x14
    // Set bit[1] to 1 --> 0x20; // Turn LED ON
    // Set bit[1] to 0 --> 0x0; // Turn LED OFF

    while(1)
    {
      GPIOA->ODR |= GPIO_ODR_OD5;
      delay(100000);
        
      GPIOA->ODR &= ~GPIO_ODR_OD5;
      delay(100000);
    }    

}
#endif