#pragma once

class ZMap;

class ZMapEaseToState
{
public:
	float m_fLastOutput;
	float m_fLastInput;
	float m_fStartInput;
	float m_fStartOutput;
	bool m_bHighState;
	const ZMap* m_MapFunction; //Original declaration: const ZMap& m_MapFunction

	ZMapEaseToState() = default;
	ZMapEaseToState(const ZMap& MapFunction);
	~ZMapEaseToState() = default;
	float Map(float fInput) const;
	float Map(float fInput, bool bHighState);
	void Force(float fInput, float fOutput, bool bHighState);
};
