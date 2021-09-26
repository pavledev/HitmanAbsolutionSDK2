#pragma once

#include "ZPF5Location.h"
#include "ZPathfinderSearchState.h"
#include "TRefCountPtr.h"
#include "EPathRequestStatus.h"

class ZPF5Path;

class ZPF5AsynchPathRequest
{
public:
	int m_nRefCount;
	bool m_bReady;
	ZPF5Location m_lFrom;
	ZPF5Location m_lTo;
	const ZPathfinderSearchState::SSearchNode* m_pSearchNode;
	TRefCountPtr<ZPF5Path> m_pathResult;
	unsigned int m_nNodeKeyTo;
	float m_fMaxCost;
	EPathRequestStatus m_ePathRequestStatus;

	ZPF5AsynchPathRequest(const ZPF5AsynchPathRequest& __that);
	ZPF5AsynchPathRequest() = default;
	int AddRef() const;
	int Release() const;
	bool IsReady() const;
	TRefCountPtr<ZPF5Path>& GetResult();
	~ZPF5AsynchPathRequest() = default;
	ZPF5AsynchPathRequest& operator=(const ZPF5AsynchPathRequest& __that);
};
