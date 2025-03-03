#include "console_screen.h"

int main(void)
{
	init_screen(20, 10);
	
	push_pixel('&', 10, 5);
	draw_screen();

	release_screen();
	return 0;
}
