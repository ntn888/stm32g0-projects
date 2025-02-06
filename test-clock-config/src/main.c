//#include <stdint.h>
#include "stm32g0xx.h"

#define LED_PIN 4

/*
  32.768K LSE ->
  16MHz HSI -> SYSCLK system clock <default HSI16 frequency>
*/

static void SystemClock_Config()
{
  SystemCoreClockUpdate();
}

uint32_t ticks;

void systick_handler()
{
  ticks++;
}

void delay_ms(uint32_t milliseconds)
{
  uint32_t start = ticks;
  uint32_t end = start + milliseconds;

  if (end < start) // handle overflow
  {
    while (ticks > start); // wait for ticks to wrap around to zero
  }

  while (ticks < end);
}


void main(void)
{
  SystemClock_Config();
  SysTick_Config(16000);
  __enable_irq();
  
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
  while(1)
  {
    GPIOA->ODR ^= (1<<LED_PIN);  // toggle diodes
    delay_ms(500);
  }
}
