#include "console_screen.h"
#include "convert_screen.h"
#include <stdio.h>
#include <math.h>

void convert_screen(float x, float y, int *screenX, int *screenY) {
    int width = get_screen_width();
    int height = get_screen_height();

    *screenX = (int)((x+1)/2 * (width-1));
    *screenY = (int)((1-y)/2*(height-1));

    
}


void draw_point(float x, float y) {
    int screenX, screenY;
    convert_screen(x, y, &screenX, &screenY);
    push_pixel('@', screenX, screenY);
}