#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"

/*Dog 2*/
void dog_two()
{
  dogState2 = 1;

  clearScreen(COLOR_MAGENTA);

  drawString8x12(35, 40, "My dog KIRA", COLOR_GOLD, COLOR_MAGENTA);

  //face
  fillRectangle(35, 90, 60, 60, COLOR_WHITE);
  //left spot
  fillRectangle(35, 90, 10, 10, COLOR_GRAY);
  //left eye
  fillRectangle(40, 100, 20, 10, COLOR_BLACK);
  //right eye
  fillRectangle(70, 100, 20, 10, COLOR_BLACK);
  //right spot
  fillRectangle(80, 90, 10, 20, COLOR_BROWN);
  //nose
  drawIsoTriangle(65, 120, 12, 12, COLOR_BLACK);
  //left ear
  drawIsoTriangle(35, 68, 22, 22, COLOR_WHITE);
  //right ear
  drawIsoTriangle(73, 68, 22, 22, COLOR_WHITE);		
}

/*dog 3*/
void dog_3()
{
  dogState3 = 1;

  clearScreen(COLOR_PINK);

  drarString8x12(35, 40, "My dog MISHKA", COLOR_ROYAL_BLUE, COLOR_PINK);

  //face
  fillRectangle(20, 70, 60, 60, COLOR_BLACK);
  //left spot
  fillRectangle(20, 75, 15, 15, COLOR_BROWN);
  //left eye
  fillRectangle(25, 85, 10, 10, COLOR_NAVY);
  //right eye
  fillRectangle(60, 85, 10, 10, COLOR_NAVY);
  //nose
  fillRectangle(40, 90, 10, 10, COLOR_HOT_PINK);
  //left ear
  drawIsoTriangle(15, 48, 22, 22, COLOR_BLACK);
  //right ear
  drawIsoTriangle(53, 48, 22, 22, COLOR_BLACK);
}

/*dog 4*/
void dog_four()
{
  dogState4 = 1;

  clearScreen(COLOR_ROYAL_BLUE);

  drawString8x12(20, 10, "My dog PINKY", COLOR_RED, COLOR_ROYAL_BLUE);

  //face
  fillRectangle(20, 60, 60, 150, COLOR_KHAKI);
  //left eye
  fillRectangle(21, 70, 25, COLOR_BLACK);
  //right eye
  fillRectangle(51, 70, 25, COLOR_BLACK);
  //nose
  fillRectangle(39, 82, 20, 5, COLOR_PINK);
  //left ear
  fillRectangle(20, 55, 5, 10, COLOR_KHAKI);
  //right ear
  fillRectangle(20, 60, 5, 10, COLOR_KHAKI);  
}


























