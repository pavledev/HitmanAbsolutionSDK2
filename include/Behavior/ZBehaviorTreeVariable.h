#pragma once

#include "EBehaviorTreeVariableType.h"

class ZBehaviorTreeVariable
{
public:
	EBehaviorTreeVariableType m_eType;
	unsigned int m_nIndex;

	ZBehaviorTreeVariable() = default;
	~ZBehaviorTreeVariable() = default;
	static void RegisterType();
	ZBehaviorTreeVariable(EBehaviorTreeVariableType eType, unsigned int nIndex);
	EBehaviorTreeVariableType GetType() const;
	unsigned int GetIndex() const;
	bool IsValid() const;
	bool IsIndexValid() const;
};
