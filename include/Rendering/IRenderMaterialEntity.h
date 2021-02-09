#pragma once

#include "IComponentInterface.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "ZResourcePtr.h"
#include "STextureModifier.h"
#include "SFloatModifier.h"
#include "SFloat2Modifier.h"
#include "SFloat3Modifier.h"
#include "SFloat4Modifier.h"
#include "SColor3Modifier.h"
#include "SColor4Modifier.h"

class IRenderMaterialEntity : public IComponentInterface
{
public:
	enum UnkEnum : __int32
	{
		MAX_TARGET_GEOMS = 0x5
	};

	enum EModifierOperation : __int32
	{
		eLeave = 0x0,
		eReplace = 0x1,
		eModulate = 0x2,
		eAdd = 0x3,
		eColor = 0x80
	};

	enum EModifierChangeFlag : __int32
	{
		eStructureChangeFlag = 0x1,
		eParameterChangeFlag = 0x2,
		eParameterTextureChangeFlag = 0x4
	};

	class SModifierDesc
	{
	public:
		TArray<ZString> m_sTextureNames;
		TArray<ZString> m_sFloatNames;
		unsigned int m_nNumFloatNames;
		unsigned int m_nNumFloat2Names;
		unsigned int m_nNumFloat3Names;
		unsigned int m_nNumFloat4Names;
		TArray<ZString> m_sColorNames;
		unsigned int m_nNumColor3Names;
		unsigned int m_nNumColor4Names;
	};

	class SModifierValues
	{
		TArrayRef<STextureModifier> m_TextureModifiers;
		TArrayRef<SFloatModifier> m_FloatModifiers;
		TArrayRef<SFloat2Modifier> m_Float2Modifiers;
		TArrayRef<SFloat3Modifier> m_Float3Modifiers;
		TArrayRef<SFloat4Modifier> m_Float4Modifiers;
		TArrayRef<SColor3Modifier> m_Color3Modifiers;
		TArrayRef<SColor4Modifier> m_Color4Modifiers;
		TArrayRef<ZResourcePtr> m_TextureResourcePtrs;
	};

	class SModifierDefaultValues
	{
		TArray<STextureModifier> m_TextureModifiers;
		TArray<SFloatModifier> m_FloatModifiers;
		TArray<SFloat2Modifier> m_Float2Modifiers;
		TArray<SFloat3Modifier> m_Float3Modifiers;
		TArray<SFloat4Modifier> m_Float4Modifiers;
		TArray<SColor3Modifier> m_Color3Modifiers;
		TArray<SColor4Modifier> m_Color4Modifiers;
	};
};
