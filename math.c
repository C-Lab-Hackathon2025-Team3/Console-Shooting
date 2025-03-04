#include <math.h>
#include <stdio.h>
#include "math.h"


vec4_t add_v4v4(const vec4_t* v1,const vec4_t* v2)
{
	return (vec4_t) { v1->v[0] + v2->v[0] , v1->v[1] + v2->v[1] , v1->v[2] + v2->v[2] , v1->v[3] + v2->v[3] };
}

vec3_t add_v3v3(const vec3_t* v1, const vec3_t* v2)
{
	return (vec3_t) { v1->v[0] + v2->v[0], v1->v[1] + v2->v[1], v1->v[2] + v2->v[2]};
}

vec4_t sub_v4v4(const vec4_t* v1, const vec4_t* v2)
{
	return (vec4_t) { v1->v[0] - v2->v[0], v1->v[1] - v2->v[1], v1->v[2] - v2->v[2], v1->v[3] - v2->v[3] };
}

vec3_t sub_v3v3(const vec3_t* v1, const vec3_t* v2)
{
	return (vec3_t) { v1->v[0] - v2->v[0], v1->v[1] - v2->v[1], v1->v[2] - v2->v[2] };
}



vec4_t mul_m4v4(const mat4_t* m,const vec4_t* v)
{
	vec4_t re = {
		m->m[0][0] * v->v[0] + m->m[0][1] * v->v[1] + m->m[0][2] * v->v[2] + m->m[0][3] * v->v[3],

		m->m[1][0] * v->v[0] + m->m[1][1] * v->v[1] + m->m[1][2] * v->v[2] + m->m[1][3] * v->v[3],

		m->m[2][0] * v->v[0] + m->m[2][1] * v->v[1] + m->m[2][2] * v->v[2] + m->m[2][3] * v->v[3],

		m->m[3][0] * v->v[0] + m->m[3][1] * v->v[1] + m->m[3][2] * v->v[2] + m->m[3][3] * v->v[3]
	};

	return re;
}


vec4_t mul_v4m4(const vec4_t* v,const mat4_t* m)
{
	vec4_t re = {
		m->m[0][0] * v->v[0] + m->m[1][0] * v->v[1] + m->m[2][0] * v->v[2] + m->m[3][0] * v->v[3],

		m->m[0][1] * v->v[0] + m->m[1][1] * v->v[1] + m->m[2][1] * v->v[2] + m->m[3][1] * v->v[3],

		m->m[0][2] * v->v[0] + m->m[1][2] * v->v[1] + m->m[2][2] * v->v[2] + m->m[3][2] * v->v[3],

		m->m[0][3] * v->v[0] + m->m[1][3] * v->v[1] + m->m[2][3] * v->v[2] + m->m[3][3] * v->v[3]
	};

	return re;
}
mat4_t mul_m4m4(const mat4_t* m1,const mat4_t* m2)
{
	mat4_t re;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			re.m[i][j] = (m1->m[i][0] * m2->m[0][j]
						+ m1->m[i][1] * m2->m[1][j]
						+ m1->m[i][2] * m2->m[2][j]
						+ m1->m[i][3] * m2->m[3][j]);
		}
	}

	return re;

}

vec4_t mul_s1v4(float s,const vec4_t* v);
vec4_t mul_s1m4(float s,const mat4_t* m);

vec3_t mul_m3v3(const mat3_t* m,const vec3_t* v);
mat3_t mul_m3m3(const mat3_t* m1,const mat3_t* m2);
vec3_t mul_s1v3(float s,const vec3_t* v)
{
	return (vec3_t) {v->v[0]*s , v->v[1]*s , v->v[2]*s };
}
vec4_t mul_s1m3(float s,const mat3_t* m);


vec4_t cross_v4(const vec4_t* v1,const vec4_t* v2);
float dot_v4(const vec4_t* v1,const vec4_t* v2);

vec3_t cross_v3(const vec3_t* v1, const vec3_t* v2)
{
	return (vec3_t) {	(v1->y * v2->z - v1->z * v2->y),
						-(v1->x * v2->z - v1->z * v2->x),
						(v1->x * v2->y - v1->y * v2->x)
	};
}
float dot_v3(const vec3_t* v1, const vec3_t* v2)
{
	return (float) {v1->x* v2->x + v1->y * v2->y + v1->z * v2->z };
}

float length_v4(const vec4_t* v);
float length_v3(const vec3_t* v)
{
	return (float)pow( (v->x*v->x + v->y * v->y + v->z * v->z), 0.5F);
}

vec4_t normalize_v4(const vec4_t* v);
vec3_t normalize_v3(const vec3_t* v)
{
	float len = length_v3(v);
	return (vec3_t) {v->x / len , v->x / len , v->z / len };
}




mat4_t translate(const mat4_t* m,const vec3_t* v)
{
	return (mat4_t){
		1.F , 0.F , 0.F , 0.F,
		0.F , 1.F , 0.F , 0.F,
		0.F , 0.F , 1.F , 0.F,
		v->v[0] , v->v[1] , v->v[2] , 1.F
	};

	
}
mat4_t rotate(const mat4_t* m,float angle,const vec3_t* v)
{
 
	float sinfv_x = sinf(angle * v->v[0]);
	float cosfv_x = cosf(angle * v->v[0]);

	float sinfv_y = sinf(angle * v->v[1]) ;
	float cosfv_y = cosf(angle * v->v[1]) ;

	float sinfv_z = sinf(angle * v->v[2]);
	float cosfv_z = cosf(angle * v->v[2]);

	mat4_t rx = {
		1.F , 0.F , 0.F , 0.F,
		0.F ,cosfv_x, sinfv_x , 0.F,
		0.F , - sinfv_x , cosfv_x , 0.F ,
		0.F , 0.F , 0.F , 1.F
	};

	mat4_t ry = {
		cosfv_y , 0.F , sinfv_y , 0.F ,
		0.F , 1.F , 0.F ,0.F,
		sinfv_y , 0.F, cosfv_y, 0.F,
		0.F , 0.F , 0.F ,1.F 
	};

	mat4_t rz = {
		cosfv_z , sinfv_z , 0.F , 0.F,
		-sinfv_z , cosfv_z , 0.F , 0.F ,
		0.F , 0.F , 1.F, 0.F ,
		0.F , 0.F , 0.F ,1.F
	};

	mat4_t rxy = mul_m4m4(&ry, &rx);
	return mul_m4m4(&rz , &rxy);

}
mat4_t scale(const mat4_t* m,const vec3_t* v)
{
	return (mat4_t) {
		v->v[0]  , 0.F	 , 0.F , 0.F,
		0.F		, v->v[1] , 0.F , 0.F,
		0.F		, 0.F	 , v->v[2],0.F,
		0.F		, 0.F	 , 0.F	, 1.F
	};
}

mat4_t lookAt(const vec3_t* eye,const vec3_t* center,const vec3_t* up)
{
	vec3_t p = *eye; //view reference point
	vec3_t n = sub_v3v3(center , eye);
	n = normalize_v3(&n);
	n = mul_s1v3(-1 , &n); //view plane normal
	vec3_t u = cross_v3(&n , up); 
	vec3_t v = cross_v3(&u , &n); //view up vector

	float translate = -dot_v3(&n, &p);

	return (mat4_t) {
		u.x , v.x , n.x , 0.F,
		u.y , v.y , n.y , 0.F,
		u.z , v.z , n.z , 0.F,
		translate , translate ,translate , 1.F
	};

	
}

mat4_t projection(float left, float right, float bottom, float top, float near, float far)
{
	return (mat4_t) {
		2*near/(right-left) , 0.F , 0.F , 0.F ,
		0.F , 2*near/(top-bottom) , 0.F , 0.F ,
		(right + left) / (right - left) , (top + bottom) / (top - bottom) , -(far + near) / (far - near) , -1.F,
		0.F, 0.F, -(2 * far * near) / (far - near), 0.F
	};
}

int absi(int n)
{
	return n < 0 ? n * -1 : n;
}


float absf(float n)
{
	return n < 0.F ? n * -1.F : n;
}


