#include "SVector3.h"

SVector3 SVector3::operator*(const float value)
{
	SVector3 answer;

	answer.x = this->x * value;
	answer.y = this->y * value;
	answer.z = this->z * value;

	return answer;
}
