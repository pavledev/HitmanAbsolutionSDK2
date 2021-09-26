#pragma once

#include "GNewOverrideBase.h"
#include "GAtomicInt.h"

class GFxResourceLibBase;

class GFxResource : public GNewOverrideBase<2>
{
public:
	enum ResourceType
	{
		RT_CharacterDef_Bit = 128,
		RT_None = 0,
		RT_Image = 1,
		RT_Font = 2,
		RT_MovieDef = 3,
		RT_SoundSample = 4,
		RT_MovieDataDef = 128,
		RT_ButtonDef = 129,
		RT_TextDef = 130,
		RT_EditTextDef = 131,
		RT_SpriteDef = 132,
		RT_ShapeDef = 133,
		RT_VideoDef = 134,
		RT_TypeCode_Mask = 65280,
		RT_TypeCode_Shift = 8
	};

	enum ResourceUse
	{
		Use_None = 0,
		Use_Bitmap = 1,
		Use_Gradient = 2,
		Use_FontTexture = 3,
		Use_SoundSample = 4,
		Use_TypeCode_Mask = 255
	};

	GAtomicInt<long> RefCount;
	GFxResourceLibBase* pLib;

	virtual ~GFxResource() = default;

	GFxResource() = default;
};
