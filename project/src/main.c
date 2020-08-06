#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"
#include "stateMachines.h"

int redrawScreen = 1;

void main(void)
{
  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  
  configureClocks();
  switch_init(); //sets up switches
  lcd_init(); //graphic display set up
  led_init();
  buzzer_init(); //buzzer set up

  clearScreen(COLOR_AQUAMARINE); //screen set up
  drawString8x12(5,50,"Arch1",COLOR_GOLD,COLOR_AQUAMARINE);
  drawString8x12(5,65,"Summer 2020", COLOR_GOLD, COLOR_AQUAMARINE);
  drawString8x12(5,80,"Mildred Brito", COLOR_GOLD, COLOR_AQUAMARINE); 

  enableWDTInterrupts(); //for interruptions

  or_sr(0x18); //CPU off, GIE on

  for(;;)
    {
      while(!redrawScreen)
	{
	  P1OUT &= ~LED_GREEN;
	  or_sr(0x18);
	}
      P1OUT |= LED_GREEN;
      __delay_cycles(250000); //delay clock to make CPU more visible when CPU is on
      redrawScreen = 0;
    }
}

void wdt_c_handler()
{
  static short count = 0;
  static short dim = 0;
  count++;
  if(count == 125)
    {
      stateAdvance();
      count = 0;
    }
  if(state == 2)
    {
      if(count == 5)
	{
	  stateAdvance();
	  count = 0;
	}
    }
}
