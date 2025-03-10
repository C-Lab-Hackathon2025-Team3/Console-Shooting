#include <stdio.h>
#include <math.h>
#include "player.h"
#include "console_screen.h"   // get_screen_width()와 get_screen_height() 함수 포함
#include "convert_screen.h"   // draw_point() 함수 포함


void draw_player(int centerX, int centerY, int radius) 
{
    for (int y = 0; y < get_screen_height(); y++) 
    {
        for (int x = 0; x < get_screen_width(); x++) 
        {
            // 원 방정식 (x - centerX)^2 + (y - centerY)^2 = radius^2
            if (fabs(pow(x - centerX, 2) + pow(y - centerY, 2) - pow(radius, 2)) < radius) 
            {
                float normX = (float)(x) / get_screen_width() * 2 - 1;
                float normY = (float)(y) / get_screen_height() * 2 - 1;

                // 원의 겉선을 그리기
                draw_point(normX, normY, '*');
            }
        }
    }
}