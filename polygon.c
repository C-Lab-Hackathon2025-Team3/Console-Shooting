#include <stdlib.h>
#include <assert.h>

#include "polygon.h"

void push_triangle(const ivec2_t* const a, const ivec2_t* const b, const ivec2_t* const c)
{
	int min_x = a->x, min_y = a->y, max_x = a->x, max_y = a->y;

	if (min_x > b->x) { min_x = b->x; }
	if (min_x > c->x) { min_x = c->x; }

	if (max_x < b->x) { max_x = b->x; }
	if (max_x < c->x) { max_x = c->x; }

	if (min_y > b->y) { min_y = b->y; }
	if (min_y > c->y) { min_y = c->y; }

	if (max_y < b->y) { max_y = b->y; }
	if (max_y < c->y) { max_y = c->y; }

	const int WIDTH = max_x - min_x;
	const int HEIGHT = max_y - min_y;
	char* buffer = malloc(WIDTH * HEIGHT);
	assert(buffer != NULL);


	free(buffer);
}
