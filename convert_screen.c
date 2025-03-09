#include "convert_screen.h"
#include "console_screen.h"

void convert_screen_coordinate(const float x, const float y, int* const out_screenX, int* const out_screenY)
{
	size_t width = get_screen_width();
	size_t height = get_screen_height();

	*out_screenX = (int)((x + 1) / 2 * (width - 1));
	*out_screenY = (int)((1 - y) / 2 * (height - 1));
}

void convert_point_array(const fvec4_t* pos, size_t length, ivec2_t* out_points)
{
	const size_t WIDTH = get_screen_width();
	const size_t HEIGHT = get_screen_height();

	for (size_t i = 0; i < length; i++)
	{
		out_points[i].x = (int)((pos[i].x + 1.F) / 2 * (WIDTH - 1));
		out_points[i].y = (int)((1.F - pos[i].y) / 2 * (HEIGHT - 1));
	}
}

void draw_point(float x, float y, char pixel)
{
	int screenX = 0, screenY = 0;
	convert_screen(x, y, &screenX, &screenY);
	push_pixel(pixel, screenX, screenY);
}
