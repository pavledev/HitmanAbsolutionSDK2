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

float4::float4(float x, float y, float z, float w)
{
	this->x() = x;
	this->y() = y;
	this->z() = z;
	this->w() = w;
}

float4::float4(SVector3 vector)
{
	this->x() = vector.x;
	this->y() = vector.y;
	this->z() = vector.z;
}
