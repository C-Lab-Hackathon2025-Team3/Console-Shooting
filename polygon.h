#pragma once
#ifndef POLYGON_H
#define POLYGON_H

#include "def.h"

typedef struct polygon_list_s
{
	struct polygon_list_s* next;
	char* buffer;
	size_t width;
	size_t height;
	int x;
	int y;
} polygon_list_t;

void push_triangle(const ivec2_t* const a, const ivec2_t* const b, const ivec2_t* const c);

//void flush_polygon_list(const polygon_list_t* const polygon_list);
//void push_polygon_by_array(const ivec2_t* const vertex_array, const int* const index_arrray);
#endif
