#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "song.h"
#include "led.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"

char switch1_state_down,
  switch2_state_down,
  switch3_state_down,
  switch4_state_down;
int state = 0;
int redrawScreen;
  

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  /*Specifies which button is pressed down*/
  switch1_state_down = (p2val & SW1) ? 0 : 1; //0 when switch1 is up
  switch2_state_down = (p2val & SW2) ? 0 : 1; //0 when switch2 is up
  switch3_state_down = (p2val & SW3) ? 0 : 1; //0 when switch3 is up
  switch4_state_down = (p2val & SW4) ? 0 : 1; //0 when switch4 is up

  /*Specifies the states (where they and and where they go to)*/
  if(switch1_state_down) /*SW1 plays song and changes background color */
    {
      state = 1;
      curr_verse = 0; //Restarts notes in song to zero
      redrawScreen = 1;
    }

  if(switch2_state_down) /*SW2 Displays my first dog*/
    {
      state = 2;
      redrawScreen = 1;
    }

  if(switch3_state_down) /*SW3 displays my second dog*/
    {
      state = 3;
      redrawScreen = 1;
    }

  if(switch4_state_down) /*SW4 displays my third dog*/
    {
      state = 4;
      redrawScreen = 1;
    }
  else
    {
      // clearWindow();
      //state = 0;
    }
}





























