#include "model_object.h"
#include "consolGL.h"
#include <stdio.h>

void save_file_object(const object_t* save_object, const char* file_name)
{
	FILE* fp = fopen(file_name, "wb");
	if (fp == NULL)
	{
		puts("파일 생성불가");
		return;
	}

	
	int debug = fwrite(&save_object->buf_size,sizeof(int),1,fp);
	debug = fwrite(save_object->vertex_array_buf, sizeof(fvec4_t), save_object->buf_size, fp);
	fclose(fp);
}

void load_file_object(object_t* load_object, const char* file_name)
{
	FILE* fp = fopen(file_name, "rb");
	if (fp == NULL)
	{
		puts("파일 안열림");
		return;
	}
	fread(&load_object->buf_size , sizeof(int) , 1 ,fp);
	load_object->vertex_array_buf = malloc(sizeof(fvec4_t)*load_object->buf_size);
	fread(load_object->vertex_array_buf, sizeof(fvec4_t), load_object->buf_size,fp);

	
	load_object->pos = (vec3_t){0.F , 0.F , 0.F};
	load_object->scale = (vec3_t){1.F , 1.F ,1.F};
	load_object->angle = 0.F;
	load_object->rot_xyz = (vec3_t){0.F ,1.F ,0.F};
	fclose(fp);
}


void release_object(object_t* model)
{
	model->buf_size = 0;
	free(model->vertex_array_buf);
}
void draw_object(const object_t* model)
{
	set_vertex_array(model->vertex_array_buf);
	scale_object(model->scale);
	rotate_object(model->angle , model->rot_xyz);
	translate_object(model->pos);

	draw_vertex_array(DRAW_TRIANGLES, 0, model->buf_size);
	
}


