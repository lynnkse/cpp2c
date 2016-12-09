#ifndef __Color__
#define __Color__

#include <stdio.h>

enum ColorEnum { Color_RED, Color_GREEN, Color_DEFAULT };

void ColorSetColor(enum ColorEnum color);
/*
struct Color 
{
	enum ColorEnum { RED, GREEN, DEFAULT };

	static void SetColor(ColorEnum color)
	{		
		static const char * pallete[] = { "\x1B[31m", "\x1B[32m", "\033[0m" };
		puts(pallete[color]);
	}
};
*/

#endif

