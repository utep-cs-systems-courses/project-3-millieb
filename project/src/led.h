#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

void led_init();
void led_update();
void toggle_on();
void toggle_off();
void led_dim();

extern unsigned char leds_changed;
extern unsigned char red_on, green_on;

#endif // included
