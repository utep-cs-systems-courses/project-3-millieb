#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char leds_changed = 0;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  leds_changed = 1;
}

void led_update()
{
  if (leds_changed)
    {
      char ledFlags = 0; //starting with leds off

      ledFlags |= leds_changed ? LED_GREEN : 0;
      ledFlags |= leds_changed ? 0 : LED_RED;

      P1OUT &= (0xff - LEDS) | ledFlags; // clear bit for off leds
      P1OUT |= ledFlags;                // set bit for on leds
    }
  leds_changed = 0;
}

void toggle_on()
{
  P1OUT = LED_RED;
  __delay_cycles(500000);
  P1OUT = LED_GREEN;
  __delay_cycles(500000);
}

void toggle_off()
{
  P1OUT = !(LED_GREEN);
  __delay_cycles(500000);
  P1OUT = !LED_RED;
  __delay_cycles(500000);
}

void led_dim()
{
  for(int i = 0; i < 1000; i++)
    {
      P1OUT = LED_RED;
      __delay_cycles(10000);
      P1OUT = LED_GREEN;
      __delay_cycles(10000);
      P1OUT = !LED_RED;
      __delay_cycles(10000);
      P1OUT = !LED_GREEN;
      __delay_cycles(10000);
    }
}

























