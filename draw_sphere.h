#pragma once
#ifndef SPHERE_H
#define SPHERE_H


#include "affine_math.h"
void sub_division_tri(int level,fvec4_t* buffer, int* start_index, const fvec4_t* p1, const fvec4_t* p2, const fvec4_t* p3);
void gen_sphere(int level, const fvec4_t* src_buffer, const int src_size, fvec4_t* dst_buffer, int* dst_size);
#endif // SPHERE_H