#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "console_screen.h"
#include "consolGL.h"

int g_state_screen_close;

mat4_t g_mvp = {
	1.F , 0.F , 0.F , 0.F,
	0.F , 1.F , 0.F , 0.F,
	0.F , 0.F , 1.F , 0.F,
	0.F , 0.F , 0.F , 1.F
};
mat4_t g_model_scale = {
	1.F , 0.F , 0.F , 0.F,
	0.F , 1.F , 0.F , 0.F,
	0.F , 0.F , 1.F , 0.F,
	0.F , 0.F , 0.F , 1.F
};

mat4_t g_model_translate = {
	1.F , 0.F , 0.F , 0.F,
	0.F , 1.F , 0.F , 0.F,
	0.F , 0.F , 1.F , 0.F,
	0.F , 0.F , 0.F , 1.F
};

mat4_t g_model_rotate = {
	1.F , 0.F , 0.F , 0.F,
	0.F , 1.F , 0.F , 0.F,
	0.F , 0.F , 1.F , 0.F,
	0.F , 0.F , 0.F , 1.F
};


mat4_t g_view = {
	1.F , 0.F , 0.F , 0.F,
	0.F , 1.F , 0.F , 0.F,
	0.F , 0.F , 1.F , 0.F,
	0.F , 0.F , 0.F , 1.F
};

mat4_t g_projection = {
	1.F , 0.F , 0.F , 0.F,
	0.F , 1.F , 0.F , 0.F,
	0.F , 0.F , 1.F , 0.F,
	0.F , 0.F , 0.F , 1.F
};
//변환 적용 구현부

void scale_object(vec3_t v) 
{
	g_model_scale = scale(&g_model_scale , &v);
}

void translate_object(vec3_t v)
{
	g_model_translate = translate(&g_model_translate, &v);
}

void rotate_object(float angle, vec3_t v)
{
	g_model_rotate =  rotate(&g_model_rotate, angle, &v);

}

void view_cam(vec3_t eye, vec3_t center, vec3_t up)
{
	g_view = lookAt(&eye, &center, &up);
}

void projection_screen(float left, float right, float bottom, float top, float near_f, float far_f)
{

}


vec4_t* vertexArrayPoint;
void set_vertex_array(vec4_t* pointer)
{
	vertexArrayPoint = (vec4_t*)pointer;
}

void draw_line_legacy(vec4_t start_pont, vec4_t dst_point)
{

	int dis_xi = (int)(dst_point.v[0] - start_pont.v[0]);
	int dis_yi = (int)(dst_point.v[1] - start_pont.v[1]);


	float cur_xf = start_pont.v[0];
	float cur_yf = start_pont.v[1];

	int totalDisi = absi(dis_xi) > absi(dis_yi) ? absi(dis_xi) : absi(dis_yi);

	float inc_xf = (float)dis_xi / totalDisi;
	float inc_yf = (float)dis_yi / totalDisi;

	for (int i = 0; i < totalDisi + 1; i++, cur_xf += inc_xf, cur_yf += inc_yf)
	{
		float origin_x = (float)get_screen_width() / 2;
		float origin_y = (float)get_screen_height() / 2;

		int put_xpos = (int)(cur_xf + origin_x);
		int put_ypos = (int)(cur_yf * (-1.F) + origin_y);
		push_pixel('*', put_xpos, put_ypos);
	}


}


void draw_polygon(vec4_t p1, vec4_t p2, vec4_t p3)
{
	//edge line
	float dis_width = (absf(p1.x - p2.x) >absf(p1.x - p3.x)) ? absf(p1.x - p2.x) : absf(p1.x - p2.x);
	dis_width = (dis_width > absf(p2.x - p3.x)) ? dis_width : absf(p2.x - p3.x);

	float dis_height = (absf(p1.x - p2.x) >absf(p1.x - p3.x)) ? absf(p1.x - p2.x) : absf(p1.x - p2.x);
	dis_height = (dis_height > absf(p2.x - p3.x)) ? dis_height : absf(p2.x - p3.x);


	for (int y = (int)dis_height; y > 0; y--)
	{
		for (int x = 0; x < (int)dis_width; x++)
		{

		}
	}



}



void draw_vertex_array(int mode, int first, int count)
{

	if (mode == DRAW_LINE)
	{
		for (int idx = first; idx < count; idx++)
		{


			vec4_t p1 = vertexArrayPoint[idx];


			p1 = (vec4_t){ p1.x , p1.y  , p1.z  , p1.w };
			p1 = mul_v4m4(&p1, &g_model_scale);
			p1 = mul_v4m4(&p1, &g_model_rotate);
			p1 = mul_v4m4(&p1, &g_model_translate);



			vec4_t p2 = vertexArrayPoint[(idx + 1) % count];

			p2 = (vec4_t){ p2.x  , p2.y  , p2.z  , p2.w };
			p2 = mul_v4m4(&p2, &g_model_scale);
			p2 = mul_v4m4(&p2, &g_model_rotate);
			p2 = mul_v4m4(&p2, &g_model_translate);

			draw_line_legacy(p1, p2);



		}

	}
	else if (mode == DRAW_LINE_TRIANGLES)
	{

		for (int idx = first; idx < count; idx += 3)
		{


			vec4_t p1 = vertexArrayPoint[idx];


			p1 = (vec4_t){ p1.x , p1.y  , p1.z  , p1.w };
			p1 = mul_v4m4(&p1, &g_model_scale);
			p1 = mul_v4m4(&p1, &g_model_rotate);
			p1 = mul_v4m4(&p1, &g_model_translate);



			vec4_t p2 = vertexArrayPoint[(idx + 1) % count];

			p2 = (vec4_t){ p2.x  , p2.y  , p2.z  , p2.w };
			p2 = mul_v4m4(&p2, &g_model_scale);
			p2 = mul_v4m4(&p2, &g_model_rotate);
			p2 = mul_v4m4(&p2, &g_model_translate);


			vec4_t p3 = vertexArrayPoint[(idx + 2) % count];

			p3 = (vec4_t){ p3.x  , p3.y  , p3.z  , p3.w };
			p3 = mul_v4m4(&p3, &g_model_scale);
			p3 = mul_v4m4(&p3, &g_model_rotate);
			p3 = mul_v4m4(&p3, &g_model_translate);

			draw_line_legacy(p1, p2);
			draw_line_legacy(p2, p3);
			draw_line_legacy(p3, p1);

		}
	}
	else if (mode == DRAW_TRIANGLES)
	{

	}
}




void draw_line(char* out_buffer, const size_t width, const size_t height, const ivec2_t* const start_point, const ivec2_t* const dest_point,char pixel)
{
	float dis_xf = (float)dest_point->v[0] - (float)start_point->v[0];
	float dis_yf = (float)dest_point->v[1] - (float)start_point->v[1];


	float cur_xf = (float)start_point->v[0];
	float cur_yf = (float)start_point->v[1];

	float totalDisi = absf(dis_xf) > absf(dis_yf) ? absf(dis_xf) : absf(dis_yf);

	float inc_xf = dis_xf / totalDisi;
	float inc_yf = dis_yf / totalDisi;

	for (int i = 0; i < (int)totalDisi+1; i++, cur_xf += inc_xf, cur_yf += inc_yf)
	{
		float origin_x = (float)width / 2;
		float origin_y = (float)height / 2;

		int put_xpos = (int)(cur_xf + origin_x);
		int put_ypos = (int)(cur_yf * (-1.F) + origin_y);
		out_buffer[put_ypos * (int)(width+1) + put_xpos] = pixel;
		
	
	}



}
