#include <msp430.h>
#include "song.h"
#include "switches.h"

int curr_verse = 0; //index of note

int verse[] = {C1, G, C1, C1, D, E, F, G, C1, G, C1, C1, D, G, F, G, G, G, Ab, Bb, C1, C1, C1, Bb, Ab, Bb, Ab, G, G, F, F, G, Ab, G, F, Eb, Eb, F, G, F, Eb, D, D, E, F1, A, G}; //piano notes

char curr_state_one = 0; //allows change between states

void play_legend_of_zelda()
{
if(curr_verse == 46) //reaches end of song
  {
    buzzer_set_period(0); //terminates
  }

 else //play song
   {
     switch(curr_state_one)
       {
       case 0:
	 buzzer_set_period(verse[curr_verse]); //play
	 curr_verse++; //moves to next note
	 curr_state_one = 1; //change case
       break;

       case 1:
	 buzzer_set_period(verse[curr_verse]); //play
	 curr_verse++;
	 curr_state_one = 0; //change case
       break;
     }
   }
}


