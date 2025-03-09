#include <stdio.h>

#include "def.h"

void convert_screen_coordinate(float x, float y, int *screenX, int *screenY);
void convert_point_array(const fvec4_t* pos, size_t length, ivec2_t* out_points);
void draw_point(float x, float y, char pixel);