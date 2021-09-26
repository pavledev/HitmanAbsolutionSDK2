#pragma once

class GMatrix3D
{
public:
	float M_[4][4];

	static GMatrix3D Identity;

	~GMatrix3D() = default;
	GMatrix3D() = default;
};
