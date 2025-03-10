#include "draw_sphere.h"

void sub_division_tri(int level,vec4_t* buffer, int* start_index, const vec4_t* p1, const vec4_t* p2, const vec4_t* p3)
{
	if (level <= 0)
	{
		buffer[*start_index] = *p1;
		buffer[*start_index+1] = *p2;
		buffer[*start_index+2] = *p3;
		start_index += 3;
	}
	else
	{
		vec4_t p1p2 = add_v4v4(p1 , p2);
		p1p2 = normalize_v4(&p1p2);

		vec4_t p2p3 = add_v4v4(p2, p3);
		p2p3 = normalize_v4(&p2p3);

		vec4_t p3p1 = add_v4v4(p3, p1);
		p3p1 = normalize_v4(&p3p1);

		sub_division_tri(level - 1,buffer,start_index,p1, &p1p2, &p3p1);

		*start_index += 3;
		sub_division_tri(level - 1, buffer, start_index,p2, &p2p3, &p1p2);

		*start_index += 3;
		sub_division_tri(level - 1, buffer, start_index, p3, &p3p1, &p2p3);

		*start_index += 3;
		sub_division_tri(level - 1, buffer, start_index, &p1p2, &p2p3, &p3p1);

	}


}

void gen_sphere(int level,const vec4_t* src_buffer,const int src_size,vec4_t* dst_buffer,int* dst_size)
{
	*dst_size = 0;
	for (int i = 0; i < src_size; i+= 3)
	{
		vec4_t p1 = src_buffer[i];
		p1 = normalize_v4(&p1);
		vec4_t p2 = src_buffer[i+1];
		p2 = normalize_v4(&p2);
		vec4_t p3 = src_buffer[i+2];
		p3 = normalize_v4(&p3);
		sub_division_tri(level,dst_buffer,dst_size,&p1, &p2 , &p3);
	}


}