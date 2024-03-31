/** 
 * --------------------------------------------------------------------------------------+  
 * @name        OLED SSD1306 example
 * --------------------------------------------------------------------------------------+ 
 *              Copyright (C) 2020 Marian Hrinko.
 *              Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @date        06.10.2020
 * @file        main.c
 * @test        AVR Atmega328p
 *
 * @depend      lib/ssd1306.h
 */

// include libraries
#include "lib/ssd1306.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @desc    Main function
 *
 * @param   void
 *
 * @return  int
 */

// ==================================== Protoypes
short button(int a);
// ==================================== Main
int main(void)
{
  // LCD INIT
  // ------------------------------------------------------------------------------------- 
  SSD1306_Init (SSD1306_ADDR);                                    // 0x3C
  int score = 0;
  char stringScore[50];

  // DRAWING
  // -------------------------------------------------------------------------------------
  SSD1306_ClearScreen ();                                         // clear screen
  SSD1306_DrawLine (0, MAX_X, 4, 4);                              // draw line
  SSD1306_SetPosition (45, 1);                                    // set position
  SSD1306_DrawString ("PINBALL");                                 // draw string
  SSD1306_DrawLine (0, MAX_X, 18, 18);                            // draw line
  
  itoa(score, stringScore, 10);
  SSD1306_SetPosition (50, 3);                                    // set position
  SSD1306_DrawString (stringScore);   
  SSD1306_UpdateScreen (SSD1306_ADDR);                            // update
  SSD1306_InverseScreen (SSD1306_ADDR);

  _delay_ms (1000);
  SSD1306_NormalScreen (SSD1306_ADDR);
  while (1) {
    if (button(PD7)) {
      score += 100;
      itoa(score, stringScore, 10);
      SSD1306_SetPosition (50, 3);                                 // set position
      SSD1306_DrawString (stringScore);                            // draw string
      _delay_ms (200);
      SSD1306_UpdateScreen (SSD1306_ADDR);                         // update
    }
  }
  // SSD1306_SetPosition (40, 3);                                    // set position
  // SSD1306_DrawString (stringScore);                               // draw string

  // SSD1306_UpdateScreen (SSD1306_ADDR);                            // update

  // _delay_ms (1000);
  // SSD1306_InverseScreen (SSD1306_ADDR);

  // _delay_ms (1000);
  // SSD1306_NormalScreen (SSD1306_ADDR);
  
  return 0;
}


/* 
 * checks when a button on the D port pressed
 */
short button(int a)
{
	int b;

	if ((PIND & (1 << a)) != 0)
	{
		/* software debounce */
		_delay_ms(15);
		if ((PIND & (1 << a)) == 0)
		{
			b = 1;
		}
	}
	else
	{
		b = 0;
	}

	return b;
}