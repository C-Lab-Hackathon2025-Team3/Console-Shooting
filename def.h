#pragma once
#ifndef DEF_H
#define DEF_H

typedef union
{
	struct
	{
		int v[2];
	};
	struct
	{
		int x;
		int y;
	};
}ivec2_t;

typedef union
{
	struct
	{
		float v[2];
	};
	struct
	{
		float x;
		float y;
	};
}fvec2_t;

typedef union
{
	struct
	{
		float v[4];
	};
	struct
	{
		float x;
		float y;
		float z;
		float w;
	};
} fvec4_t;

#endif