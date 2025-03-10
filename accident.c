#include "accident.h"
#include <math.h>

// 거리 계산 함수
float calculate_distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool check_collision(float x1, float y1, float r1, float x2, float y2, float r2) {

    float distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    // 반지름 합 비교
    return distance <= (r1 + r2);
}