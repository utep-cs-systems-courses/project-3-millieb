#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "song.h"
#include "dog.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include <libTimer.h>
#include "led.h"
#include "buzzer.h"


char dogState2 = 0;
char dogState3 = 0;
char dogState4 = 0;

/*Moving between states*/
void stateAdvance()
{
  switch(state)
    {
    case 1:
      if(curr_verse == 0)
	{
	  clearScreen(COLOR_PALE_GREEN);
	}
      play_legend_of_zelda();
      break;

    case 2:
      //reset to note 0 for state1
      curr_verse = 0;
      buzzer_set_period(0);

      //restarting dog images values
      dogState3 = 0;
      dogState4 = 0;

      if(dogState2 == 0)
	{
	  dog_two();
	}
      break;

    case 3:
      //Again restarting to note 0 for state 1
      curr_verse = 0;
      buzzer_set_period(0);

      //again restarting dog image values
      dogState2 = 0;
      dogState4 = 0;

      if(dogState3 == 0)
	{
	  dog_three();
	}
      break;

    case 4:
      //Again restarting to note 0 for state 1
      curr_verse = 0;
      buzzer_set_period(0);

      //again restarting dog image values
      dogState2 = 0;
      dogState3 = 0;

      if(dogState4 == 0)
	{
	  dog_four();
	}
      break;

    default:
      welcome();
    }
}




