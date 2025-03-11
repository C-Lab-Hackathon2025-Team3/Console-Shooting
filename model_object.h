#pragma once
#ifndef MODEL_OBJECT
#define MODEL_OBJECT
#include "def.h"
#include "affine_math.h"
typedef struct object
{
	fvec4_t* vertex_array_buf;
	int buf_size;

	vec3_t pos;
	vec3_t scale;
	float angle;
	vec3_t rot_xyz;
}object_t;

void save_file_object(const object_t* save_object,const char* file_name);

void load_file_object(object_t* load_object,const char* file_name);

void release_object(object_t* model);

void draw_object(const object_t* model);

#endif // !MODEL_OBJECT
