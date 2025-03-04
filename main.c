#include <math.h>
#include "def.h"
#include "console_screen.h"
#include "polygon.h"

int main(void)
{
	init_screen(40, 20);
	
	push_pixel('2', 20, 10);

	draw_screen();
	release_screen();
	return 0;
}
