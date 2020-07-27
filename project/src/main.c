#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"

void main(void)
{
  configureClocks();
  switch_init(); //sets up switches
  lcd_init(); //graphic display set up
  buzzer_init(); //buzzer set up

  clearScreen(COLOR_AQUAMARINE); //screen set up
  drawString8x12(35, 55, "Arch1 - Summer 2020", COLOR_GOLD, COLOR_AQUAMARINE);

  enableWDTInterrupts(); //for interruptions

  or_sr(0x18); //CPU off, GIE on
}
