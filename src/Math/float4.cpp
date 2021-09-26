#include "float4.h"
#include "Function.h"
#include "BaseAddresses.h"
#include "float1.h"

float4 float4::operator+(float4 f)
{
	float4 f2;

	f2.x() = this->x() + f.x();
	f2.y() = this->y() + f.y();
	f2.z() = this->z() + f.z();
	f2.w() = this->w() + f.w();

	return f2;
}

float4 float4::operator-(float4 f)
{
	float4 f2;

	f2.x() = this->x() - f.x();
	f2.y() = this->y() - f.y();
	f2.z() = this->z() - f.z();
	f2.w() = this->w() - f.w();

	return f2;
}
