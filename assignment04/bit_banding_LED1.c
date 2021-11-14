int counter=0;
#define GPIO_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(GPIO_BASE+0x4c)))
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE+0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE+0x14)))

int main()
{
  //RCC_AHB2ENR = RCC_AHB2ENR | 0x1; //to enable clock to PORT A
  
  
  //set bit0 of RCC_AHB2ENR register to 1 to enable Port A using bit banding
  *((unsigned int*)(0x42000000+(0x2104C*32)+(0*4)))=0x1;  
  
  
  GPIOA_MODER = GPIOA_MODER & 0xFFFFF7FF; //Set GPIO to output mode
  while(1)
  {
    counter=0;
    GPIOA_ODR = GPIOA_ODR | 0x0020; //LED1 ON
    
    while(counter<100000)
  {
      counter++;
  }
  counter=0;
   GPIOA_ODR = GPIOA_ODR & 0xFFFFFFDF; //LED1 OFF
    while(counter<100000)
  {
      counter++;
  }
  }
  return 0;
}

