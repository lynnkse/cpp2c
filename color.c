#include "color.h"

void ColorSetColor(enum ColorEnum color)
{
	static const char * pallete[] = { "\x1B[31m", "\x1B[32m", "\033[0m" };
	puts(pallete[color]);
}
