#include "float4.h"
#include "Function.h"
#include "BaseAddresses.h"

float* float4::operator[](int nSubscript)
{
	return Function::CallMethodAndReturn<float*, float4*, int>(BaseAddresses::hitman5Dll + 0x641D0, this, nSubscript);
}

float1* float4::Length3(float1* result)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*>(BaseAddresses::hitman5Dll + 0x82870, this, result);
}

float1* float4::X(float1* result)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*>(BaseAddresses::hitman5Dll + 0x84EF0, this, result);
}

float1* float4::Y(float1* result)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*>(BaseAddresses::hitman5Dll + 0x84F10, this, result);
}

float1* float4::Z(float1* result)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*>(BaseAddresses::hitman5Dll + 0x84F30, this, result);
}

float1* float4::W(float1* result)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*>(BaseAddresses::hitman5Dll + 0x84F50, this, result);
}

float1* float4::Dot2(float1* result, float4* v)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*, float4*>(BaseAddresses::hitman5Dll + 0xA31D0, this, result, v);
}

float1* float4::LengthSq2(float1* result)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*>(BaseAddresses::hitman5Dll + 0xA3630, this, result);
}

float1* float4::Length2(float1* result)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*>(BaseAddresses::hitman5Dll + 0xA9890, this, result);
}

float1* float4::LengthSq3(float1* result)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*>(BaseAddresses::hitman5Dll + 0xBF9D0, this, result);
}

float4* float4::Cross(float4* result, float4* v)
{
	return Function::CallMethodAndReturn<float4*, float4*, float4*, float4*>(BaseAddresses::hitman5Dll + 0xC1190, this, result, v);
}

float1* float4::Dot3(float1* result, float4* v)
{
	return Function::CallMethodAndReturn<float1*, float4*, float1*, float4*>(BaseAddresses::hitman5Dll + 0xC5930, this, result, v);
}

float4* float4::Normalize3Checked(float4* result)
{
	return Function::CallMethodAndReturn<float4*, float4*, float4*>(BaseAddresses::hitman5Dll + 0xE0760, this, result);
}

float4* float4::Zero(float4* result)
{
	return Function::CallAndReturn<float4*, float4*>(BaseAddresses::hitman5Dll + 0xE17D0, result);
}

float& float4::z()
{
	return Function::CallMethodAndReturn<float&, float4*>(BaseAddresses::hitman5Dll + 0x153FA0, this);
}

const float* float4::xConst()
{
	return Function::CallMethodAndReturn<const float*, float4*>(BaseAddresses::hitman5Dll + 0x1773F0, this);
}

const float* float4::yConst()
{
	return Function::CallMethodAndReturn<const float*, float4*>(BaseAddresses::hitman5Dll + 0x177400, this);
}

float& float4::x()
{
	return Function::CallMethodAndReturn<float&, float4*>(BaseAddresses::hitman5Dll + 0x189A80, this);
}

float& float4::y()
{
	return Function::CallMethodAndReturn<float&, float4*>(BaseAddresses::hitman5Dll + 0x189A90, this);
}

const float* float4::zConst()
{
	return Function::CallMethodAndReturn<const float*, float4*>(BaseAddresses::hitman5Dll + 0x18F110, this);
}

float4* float4::Normalize3(float4* result)
{
	return Function::CallMethodAndReturn<float4*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x26B6D0, this, result);
}

float4* float4::SetX(float4* result, float1* s)
{
	return Function::CallMethodAndReturn<float4*, float4*, float4*, float1*>(BaseAddresses::hitman5Dll + 0x367650, this, result, s);
}

float4* float4::SetY(float4* result, float1* s)
{
	return Function::CallMethodAndReturn<float4*, float4*, float4*, float1*>(BaseAddresses::hitman5Dll + 0x3676C0, this, result, s);
}

float4* float4::Normalize2(float4* result)
{
	return Function::CallMethodAndReturn<float4*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x40AB50, this, result);
}

float4* float4::UnitZ(float4* result)
{
	return Function::CallAndReturn<float4*, float4*>(BaseAddresses::hitman5Dll + 0x445670, result);
}

float4* float4::SetZ(float4* result, float1* s)
{
	return Function::CallMethodAndReturn<float4*, float4*, float4*, float1*>(BaseAddresses::hitman5Dll + 0x44DAA0, this, result, s);
}

float& float4::w()
{
	return Function::CallMethodAndReturn<float&, float4*>(BaseAddresses::hitman5Dll + 0x4E4E00, this);
}

const float* float4::wConst()
{
	return Function::CallMethodAndReturn<const float*, float4*>(BaseAddresses::hitman5Dll + 0x4E8920, this);
}

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
