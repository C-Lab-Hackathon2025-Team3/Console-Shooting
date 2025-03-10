#pragma once
#include "affine_math.h"
void sub_division_tri(int level,vec4_t* buffer, int* start_index, const vec4_t* p1, const vec4_t* p2, const vec4_t* p3);
void gen_sphere(int level, const vec4_t* src_buffer, const int src_size, vec4_t* dst_buffer, int* dst_size);