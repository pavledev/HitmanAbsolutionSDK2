#pragma once

class ZSoundGroupInternal;
class ZString;
struct float4;

class __declspec(novtable) ISoundGroup
{
public:
	virtual ~ISoundGroup() = default;
	virtual const ZString& GetGroupName() const = 0;
	virtual ZSoundGroupInternal* GetSoundGroupInternal() = 0;
	virtual bool AcceptsNewTarget(int param1, const float4& param2) = 0;

	static void RegisterType();
	ISoundGroup() = default;
};
