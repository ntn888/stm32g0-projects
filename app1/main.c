//#include <stdint.h>
#include "stm32g0xx.h"

#define LED_PIN 5

void main(void)
{
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
  while(1)
  {
    GPIOA->ODR ^= (1<<LED_PIN);  // toggle diodes
    for (uint32_t i = 0; i < 1000000; i++);
  }
}

