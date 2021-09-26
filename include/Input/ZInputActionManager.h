#pragma once

#include "IComponentInterface.h"
#include "ZGameTime.h"
#include "ZVariantRef.h"

struct SComponentMapEntry;
class ZActionMapTree;
class ZInputTokenStream;
struct STypeID;

class ZInputActionManager : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZActionMapTree* m_pkRoot;
	ZActionMapTree* m_pkCurrentBlock;
	int m_iBindMem;
	bool m_bDebugKeys;
	bool m_bEnabled;
	bool m_bSpeedRepeat;
	bool m_JoinControllers;
	ZGameTime m_EventHorizonDelay;

	static int m_iSeq;

	~ZInputActionManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZInputActionManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void ResetTime();
	void SetJoinControllers(bool bJoin, int iDevice);
	bool GetJoinControllers();
	void OverrideDevice(int nDeviceID);
	void RevertToDefault();
	void DisableInputTimer(float deltaTime);
	ZGameTime GetDisableInputTimers();
	void Enable();
	void Disable();
	bool IsEnabled();
	bool AddBindings(const char* const binds);
	bool LoadBindings(const char* szFilename);
	void ClearBindings();
	char* GetKeyName(const char* szAction);
	char* GetSystemKeyName(const char* szAction, bool firstKey);
	void DisplayBinds(ZActionMapTree* pkMap, int indent);
	void DisplayMemInf();
	void SetDebugKeys(bool bDebugKeys);
	bool GetDebugKeys();
	int SeqNr();
	ZActionMapTree* GetMapping(ZActionMapTree* node, const char* name);
	ZActionMapTree* GetMapping(const char* name);
	void SetSpeedRepeat(bool bSpeedRepeat);
	bool GetSpeedRepeat();
	bool ParseBinds(ZInputTokenStream* pkStream);
	ZActionMapTree* ParseAsignment(ZInputTokenStream* pkStream);
	ZActionMapTree* ParseExp(ZInputTokenStream* pkStream);
	ZActionMapTree* ParseBlock(ZInputTokenStream* pkStream, char* pzName);
	void DeleteTree(ZActionMapTree* pkMap);
	ZActionMapTree* AllocMap();
	void FreeMap(ZActionMapTree* pkMap);
};
