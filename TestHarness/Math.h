#pragma once

#include <math.h>

#undef  PI
#define PI 				(3.1415926535897932f)
#define SMALL_NUMBER =	(1.e-8f)

namespace Math
{

long double Sqrt(const long double inVal)
{
	return sqrt(inVal);
}

float Sqrt(const float inVal)
{
	return sqrtf(inVal);
}

}