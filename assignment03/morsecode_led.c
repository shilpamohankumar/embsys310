#define GPIO_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(GPIO_BASE+0x4c)))
#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE+0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE+0x14)))
#define MORSECODE_CHAR_LENGTH 5
#define STRING "shilpa"
#define SIZE sizeof(STRING)-1
#include<string.h>
void delay(int delay_count)
{
  int counter=0;
  while(counter<delay_count)
  {
    counter++;
  }
}

 void flash_led(char *morsecode)
{
  int j=0;
  for(j=0;morsecode[j]!='\0';j++)
  {
      GPIOA_ODR = GPIOA_ODR | 0x0020; //LED1 ON
      if(morsecode[j]=='.')
      {
        delay(300000);
      }
      else if(morsecode[j]=='-')
      {
        delay(300000*3);
      }
      GPIOA_ODR = GPIOA_ODR & 0xFFFFFFDF; //LED1 OFF
      delay(300000);
  }
   delay(300000*2);
}

int main()
{
    char string[SIZE];
    strcpy(string,STRING);
  
    int i=0;
    char *morsecode[]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};   //morsecode for alphabets from A-Z
    
    RCC_AHB2ENR = RCC_AHB2ENR | 0x1; //to enable clock to PORT A
    GPIOA_MODER = GPIOA_MODER & 0xFFFFF7FF; //Set GPIO to output mode
   
    while(string[i]!='\0')
    {
        flash_led(morsecode[string[i]-'a']);
        i++;
    }
    return 0;
}   
    