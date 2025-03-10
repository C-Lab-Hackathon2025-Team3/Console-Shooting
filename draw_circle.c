#include <stdio.h>
#include "draw_circle.h"
#include "console_screen.h"

// 화면에 픽셀을 출력하는 함수
//void push_pixel(char pixel, int x, int y) {
//    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
//        // 콘솔에 픽셀을 출력하는 코드
//        // x, y 좌표가 화면 범위 내에 있을 때만 출력
//        printf("\033[%d;%dH%c", y + 1, x + 1, pixel); // ANSI Escape Code로 위치 지정 후 출력
//    }
//}

// 원을 그리는 함수
void draw_circle(Circle* circle) {
    for (int y = -RADIUS; y <= RADIUS; y++) {
        for (int x = -RADIUS; x <= RADIUS; x++) {
            if (x * x + y * y <= RADIUS * RADIUS) {  // 원의 방정식: x^2 + y^2 <= r^2
                push_pixel(circle->pixel, (int)(circle->x + x), (int)(circle->y + y));
            }
        }
    }
}

// 원을 이동시키는 함수
void move_circle(Circle* circle) {
    circle->x += circle->speedX;  // x축으로 이동
    circle->y += circle->speedY;  // y축으로 이동
}
