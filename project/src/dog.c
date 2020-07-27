#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"

/*Dog 2*/
void dog_two()
{
  dogState2 = 1;

  clearScreen(COLOR_MAGENTA);

  drawString8x12(50,40,"KIRA",COLOR_GOLD,COLOR_MAGENTA);

  //face
  fillRectangle(35,90,60,60,COLOR_WHITE);
  //left spot
  fillRectangle(35,90,20,20,COLOR_GRAY);
  //left eye
  fillRectangle(40,100,10,10,COLOR_BLACK);
  //right eye
  fillRectangle(70,100,10,10,COLOR_BLACK);
  //right spot
  fillRectangle(74,129,20,20,COLOR_BROWN);
  //nose
  drawIsoTriangle(55,110,12,12,COLOR_BLACK);
  //left ear
  drawIsoTriangle(35,68,22,22,COLOR_WHITE);
  //right ear
  drawIsoTriangle(72,68,22,22,COLOR_WHITE);		
}

/*dog 3*/
void dog_three()
{
  dogState3 = 1;

  clearScreen(COLOR_PINK);

  drawString8x12(35,20,"MISHKA",COLOR_ROYAL_BLUE,COLOR_PINK);

  //face
  fillRectangle(20,70,60,60,COLOR_BLACK);
  //left spot
  fillRectangle(20,75,15,15,COLOR_BROWN);
  //left eye
  fillRectangle(25,85,10,10,COLOR_NAVY);
  //right eye
  fillRectangle(60,85,10,10,COLOR_NAVY);
  //nose
  fillRectangle(45,90,10,10,COLOR_HOT_PINK);
  //left ear
  drawIsoTriangle(20,48,22,22,COLOR_BLACK);
  //right ear
  drawIsoTriangle(57,48,22,22,COLOR_BLACK);
}

/*dog 4*/
void dog_four()
{
  dogState4 = 1;

  clearScreen(COLOR_ROYAL_BLUE);

  drawString8x12(45,20,"PINKY",COLOR_RED,COLOR_ROYAL_BLUE);

  //face
  fillRectangle(20,60,60,150,COLOR_WHITE);
  //left eye
  fillRectangle(31,70,15,15,COLOR_BLACK);
  //right eye
  fillRectangle(61,70,15,15,COLOR_BLACK);
  //nose
  fillRectangle(48,85,10,5,COLOR_PINK);
  //left ear
  fillRectangle(6,60,10,25,COLOR_WHITE);
  //right ear
  fillRectangle(83,60,10,25,COLOR_WHITE);  
}


























