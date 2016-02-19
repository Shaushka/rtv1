#include "rtv1.h"
#include <math.h>

float		d_cos(float angle)
{
	return (cos(angle * RATIO));
}

float		d_sin(float angle)
{
	return (sin(angle * RATIO));
}

float		d_acos(float value)
{
	return (d_acos(value) * (180 / PI));
}
