#pragma once

class GFxResourceId
{
public:
	enum IdTypeConstants
	{
		IdType_Bit_IndexMask = 65535,
		IdType_Bit_TypeMask = 268369920,
		IdType_Bit_SWF = 0,
		IdType_Bit_Static = 65536,
		IdType_Bit_Export = 131072,
		IdType_Bit_GenMask = 196608,
		IdType_Bit_TypeShift = 18,
		InvalidId = 262144
	};

	enum IdType
	{
		IdType_None = 0,
		IdType_InternalConstant = 65536,
		IdType_GradientImage = 327680,
		IdType_DynFontImage = 589824,
		IdType_FontImage = 393216
	};

	class HashOp
	{
	};

	unsigned long Id;

	GFxResourceId() = default;
	~GFxResourceId() = default;
};
