
#include "rtv1.h"

float		resolve_equa_2nd(float a, float b float c)
{
	float	det;

	det = b * b - 4 * a * c;
	if (det < 0.0f)
		return (0);
	else if (((-b + sqrt(det)) / (2 * a)) < ((-b - sqrt(det)) / (2 * a)))
		det = ((-b + sqrt(det)) / (2 * a));
	else
		det = ((-b - sqrt(det)) / (2 * a));
		return (det);
}
