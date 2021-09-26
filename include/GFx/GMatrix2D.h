#pragma once

class GMatrix2D
{
public:
	float M_[2][3];

	static GMatrix2D Identity;

	~GMatrix2D() = default;
	GMatrix2D() = default;
};
