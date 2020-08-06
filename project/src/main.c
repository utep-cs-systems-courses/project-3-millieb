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
  P1DIR |= LED_GREEN; //Green LED on when CPU on
  P1OUT |= LED_GREEN;
  
  configureClocks(); //init clocks
  switch_init(); //sets up switches
  lcd_init(); //graphic display set up
  led_init(); //init led
  buzzer_init(); //buzzer set up

  clearScreen(COLOR_AQUAMARINE); //welcome/main screen set up
  drawString8x12(5,50,"Arch1",COLOR_GOLD,COLOR_AQUAMARINE);
  drawString8x12(5,65,"Summer 2020", COLOR_GOLD, COLOR_AQUAMARINE);
  drawString8x12(5,80,"Mildred Brito", COLOR_GOLD, COLOR_AQUAMARINE); 

  enableWDTInterrupts(); //enable periodic interruption

  or_sr(0x18); //CPU off, GIE on

  for(;;) //copied from demo but, similar to while loop?
    {
      while(!redrawScreen)
	{ //pause if CPU does not need updating
	  P1OUT &= ~LED_GREEN; //Green LED off without CPU
	  or_sr(0x18);
	}
      P1OUT |= LED_GREEN; //Green LED ON when CPU on
      __delay_cycles(250000); //delay clock to make CPU more visible when CPU is on
      redrawScreen = 0;
    }
}


void wdt_c_handler()
{
  static short count = 0;
  static short dim = 0;
  count++;
  if(count == 100)
    {
      stateAdvance();
      count = 0;
    }
}
