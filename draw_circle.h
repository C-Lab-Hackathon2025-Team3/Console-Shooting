#pragma once
#ifndef DRAW_CIRCLE_H
#define DRAW_CIRCLE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCREEN_WIDTH (100)  // 화면 너비
#define SCREEN_HEIGHT (30)  // 화면 높이
#define RADIUS (4)          // 원의 반지름

// 원 구조체 정의
typedef struct {
    float x, y;  // 원의 중심 좌표
    float speedX, speedY;  // 원의 이동 속도
    char pixel;  // 원을 그릴 때 사용할 문자
} Circle;

// 함수 선언
void draw_circle(Circle* circle);  // 원 그리기 함수
void move_circle(Circle* circle);  // 원 이동 함수
void push_pixel(char pixel, int x, int y);  // 픽셀을 화면에 출력하는 함수
#endif