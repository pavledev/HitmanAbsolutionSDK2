#pragma once

class __declspec(novtable) ZMap
{
public:
	float m_fFirstHalf;
	bool m_bFlipInput : 1;
	bool m_bFlipOutput : 1;
	bool m_bMirror : 1;
	bool m_bAllowModifiers : 1;

	virtual ~ZMap() = default;
	virtual float MapFunction(float param1) const = 0;

	ZMap() = default;
	ZMap(const ZMap& __that);
	ZMap(bool bFlipInput, bool bFlipOutPut, bool bMirror, float fFirstHalf);
	float Map(float fInput) const;
	float Map1To1(float fInput) const;
	void SetMirror(bool b);
	void SetAllowModifiers(bool b);
	ZMap& operator=(const ZMap& __that);
};
