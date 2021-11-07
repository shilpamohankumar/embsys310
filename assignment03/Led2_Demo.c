int counter=0;
#define GPIO_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(GPIO_BASE+0x4c)))
#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE+0x0)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE+0x14)))
int main()
{
  RCC_AHB2ENR = RCC_AHB2ENR | 0x2; //to enable clock to PORT B
  GPIOB_MODER = GPIOB_MODER & 0xDFFFFFFF; //Set GPIO to output mode
  
  while(1)
  {
    counter=0;
    GPIOB_ODR = GPIOB_ODR | 0x4000; //LED ON
    
    while(counter<100000)
  {
      counter++;
  }
  counter=0;
   GPIOB_ODR = GPIOB_ODR & 0xFFFFBFFF; //LED OFF
     while(counter<100000)
  {
      counter++;
  }
  }
  return 0;
}
