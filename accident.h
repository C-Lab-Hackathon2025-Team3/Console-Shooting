#ifndef COLLISION_H
#define COLLISION_H

#include <stdbool.h>

float calculate_distance(float x1, float y1, float x2, float y2);
bool check_collision(float x1, float y1, float r1, float x2, float y2, float r2);

#endif