#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32)
#include <Windows.h>
#else
#include <unistd.h>  // sleep()
#endif
#include "console_screen.h"  
#include "convert_screen.h"  
#include "player.h"         

int main() {
    int centerX = get_screen_width() / 2;
    int centerY = get_screen_height() / 2;
    int radius = 5;

    // 화면 초기화
    init_screen(get_screen_width(), get_screen_height());


    draw_player(centerX, centerY, radius);

    draw_screen();

    clear_screen();

    getchar();  // getch() 대신 getchar() 사용

    // 리소스 해제
    release_screen();

    return 0;
}