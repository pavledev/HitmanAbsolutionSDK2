#pragma once

#include "SQuaternion.h"
#include "float4.h"

struct SMatrix;

struct SQV
{
	enum EIdentity
	{
		IDENTITY = 0
	};

	SQuaternion m_Rotation;
	float4 m_Translation;

	SQV(const SMatrix& m);
	SQV(EIdentity __formal);
	SQV() = default;
	~SQV() = default;
	void LoadIdentity();
	SQV operator*(const SQV& rhs) const;
	SQV SQVTransform(const SQV& rhs) const;
	SQV AffineInverse() const;
	SQV AffineMultiplyInverse(const SQV& rhs) const;
};
