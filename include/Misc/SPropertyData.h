#pragma once

struct SPropertyInfo;

struct SPropertyData
{
	unsigned int m_nPropertyID;
	int m_nPropertyOffset;
	const SPropertyInfo* m_pInfo;

	SPropertyData() = default;
	~SPropertyData() = default;
	bool IsRuntimeEditableOrConstAfterStart() const;
	bool IsStreamable() const;
	bool ShouldCallSetter(bool bPostInit) const;
};
