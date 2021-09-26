#pragma once

#include "IComponentInterface.h"
#include "MR.h"
#include "SMatrix.h"
#include "ZMutex.h"
#include "ZDelegate.h"
#include "TMap.h"
#include "ZEntityRef.h"
#include "THashMap.h"
#include "SVector4.h"
#include "SMorphemeData.h"
#include "SQV.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "ZAnimationRig.h"
#include "ZRuntimeResourceID.h"
#include "ZString.h"
#include "ZVariantRef.h"
#include "float4.h"

struct SMorphemeNetworkCreationData;
struct SIOIAttribDataTime;
struct SIOIEvent;
class IVariationInstance;
class IChildNetworkEntity;
class IJobChain;
class IJob;
class ZAnimationBoneData;
namespace NMP {
class DataBuffer;
}  // namespace NMP
struct SBoneDefinition;
struct SComponentMapEntry;
struct SCutSequenceData;
struct SMatrix43;
struct STypeID;
struct ZChildNetworkEntry;
struct float1;
template <class A, class B> class TDefaultHashMapPolicy;
template <class A, int B> class TMaxArray;

class ZMorphemeNetworkInstance : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	struct SAsyncData
	{
		ZMorphemeNetworkInstance* m_pMorphemeNetworkInstance;
		int m_niid;
		float m_fDeltaTime;
	};

	struct SInterpolatingParameter
	{
		SVector4 m_oldValue;
		SVector4 m_newValue;
		float m_fTimeTotal;
		float m_fTimeCurrent;

		SInterpolatingParameter(const float4& oldValue, const float4& newValue, float fTimeTotal);
	};

	struct SMorphemeDataImpl : SMorphemeData
	{
		TMap<ZString, SCutSequenceData> m_EvaluationCutSequenceDataMap;

		~SMorphemeDataImpl() override = default;
		const SCutSequenceData* GetCutSequenceData(const char* pszSlotName) const override;
		unsigned int GetNumberOfDeformBones() const override;
		const TArrayRef<SQV> GetMeshBindPose() const override;
		int* GetMeshIDToRigIDMap() const override;
		int* GetMeshHierarchy() const override;
		const SBoneDefinition* GetBoneDefinitions() const override;

		void CopyCutSequenceDataMap(const TMap<ZString, SCutSequenceData>& copyFrom);
		SMorphemeDataImpl() = default;
	};

	ZString m_sLastError;
	ZString m_sDebugName;
	MR::Network* m_pNetwork;
	MR::NetworkDef* m_pNetworkDef;
	SMatrix* m_pTransForms;
	ZMutex m_asyncMutex;
	ZDelegate<void __cdecl(int)> m_networkUpdateCompleteDelegate;
	TMap<ZString, SCutSequenceData> m_CutSequenceDataMap;
	SMorphemeDataImpl m_morphemeData;
	float m_fPlayBackSpeedFactor;
	unsigned short m_nBipIndex;
	bool m_bIsUpdatedByMediator;
	bool m_bDeferTransformUpdate;
	ZEntityRef m_pOwnerEntity;
	TMap<unsigned int, ZChildNetworkEntry> m_aChildNetworkSlots;
	THashMap<unsigned int, SInterpolatingParameter, TDefaultHashMapPolicy<unsigned int, SInterpolatingParameter>> m_InterpolatingControls;
	IJob* m_pJob;
	SAsyncData m_asyncUpdateData;

	~ZMorphemeNetworkInstance() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZMorphemeNetworkInstance() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	static ZMorphemeNetworkInstance* Create(const SMorphemeNetworkCreationData& creationData, const ZDelegate<void __cdecl(int)>& networkUpdateCompleteCallback);
	MR::NetworkDef* GetNetworkDef();
	void UpdateNetworkFullAsync(IJobChain* pJobChain, const float fDeltaTime, const int id);
	void UpdateNetworkFull(float fDeltaTime, bool bIsOnMainThread);
	void DeferTransformUpdate(bool bFlag);
	bool IsDeferringTransformUpdate() const;
	bool GetTransformBuffer(NMP::DataBuffer* transformBuffer) const;
	const TArrayRef<SQV> GetTransformBuffer() const;
	void GetBounds(float4& vMin, float4& vMax) const;
	int GetParentBoneIndex(int nBoneIndex) const;
	float4 GetPositionChange() const;
	SMatrix GetOrientationChange() const;
	SMatrix GetTrajectoryDelta() const;
	SQV GetAnimationTrajectoryDelta(unsigned int iNode, float fRelTime0, float fRelTime1) const;
	void GetBoneCache(unsigned int nNodeId, float fTimeFraction, TArray<SQV>& boneCache);
	void GetSelectSourceAnimNodeIds(const unsigned int nSelectNodeId, TMaxArray<unsigned int, 24>& anAnimNodeIds) const;
	void GetSelectMatchEventsSourceAnimNodeIds(const unsigned int nSelectNodeId, TMaxArray<unsigned int, 24>& anAnimNodeIds) const;
	float GetAnimationDuration(unsigned int iNode) const;
	unsigned int GetAnimationNodeId(unsigned int nParentNode);
	unsigned int GetActiveAnimationNodeId(unsigned int nNodeId) const;
	void FindEventTimes(ZString sEventTrackName, unsigned int nEventID, TArray<float>& eventTimes);
	TArray<ZString> GetControlParameters() const;
	unsigned int GetControlParamID(const char* sControlParamName) const;
	STypeID* GetControlParamTypeID(unsigned int nControlParameterID) const;
	ZString GetControlParamName(unsigned int nControlParamID) const;
	bool ControlParameterExists(const char* sParameterName) const;
	float4 GetControlParameter(unsigned int nControlParameterID) const;
	float4 GetControlParameter(const char* sParameterName) const;
	float GetControlParameterAsFloat(const char* sParameterName) const;
	float GetControlParameterAsFloat(unsigned int nControlParameterID) const;
	float GetControlParameterInterpSpeed(unsigned int nControlParameterID) const;
	float4 GetControlParameterInterpTarget(unsigned int nControlParameterID) const;
	float4 GetControlParameterInterpTarget(unsigned int nControlParameterID, float& fTimeRemaining) const;
	float GetControlParameterInterpTargetAsFloat(unsigned int nControlParameterID) const;
	float GetControlParameterInterpTargetAsFloat(unsigned int nControlParameterID, float& fTimeRemaining) const;
	void SetControlParameter(const char* sParameterName, float newValue);
	void SetControlParameter(unsigned int nControlParameterID, float newValue);
	void SetControlParameter(const char* sParameterName, const float4& newValue);
	void SetControlParameter(unsigned int nControlParameterID, const float1& newValue);
	void SetControlParameter(unsigned int nControlParameterID, const float4& newValue);
	void SetNonInterpolatingControlParameter(unsigned int nControlParameterID, float newValue);
	void SetNonInterpolatingControlParameter(unsigned int nControlParameterID, const float1& newValue);
	void SetNonInterpolatingControlParameter(unsigned int nControlParameterID, const float4& newValue);
	bool IsControlParameterInterpolating(unsigned int nControlParameterID);
	void InterpControlParameter(const char* sParameterName, float newValue, const float fTime);
	void InterpControlParameter(const char* sParameterName, const float4& newValue, const float fTime);
	void InterpControlParameter(unsigned int nControlParameterID, float newValue, const float fTime);
	void InterpControlParameter(unsigned int nControlParameterID, const float4& newValue, const float fTime);
	bool ForwardControlParameter(const char* sParameterName, unsigned int nNodeId, unsigned int nControlParameterID) const;
	bool ForwardControlParameter(const char* sParameterName, unsigned int nNodeId) const;
	bool ChildNetworkControlParameterExists(unsigned int nNodeID, const char* sParameterName) const;
	void ResetAllStateMachines();
	bool SendRequestToActiveStateMachines(unsigned int nRequestID, bool bIgnoreTransitions);
	bool SendRequestToActiveStateMachines(const ZString& sRequestName, bool bIgnoreTransitions);
	bool SendRequestToStateMachine(unsigned int nStateMachineID, unsigned int nRequestID);
	bool BroadcastRequestToAllStateMachines(int nRequestID);
	bool WillRequestBeReceived(unsigned int nStateMachineId, unsigned int nNodeID, unsigned int nRequestID) const;
	bool WillRequestBeReceived(const unsigned int nRequestID) const;
	bool WillRequestBeReceived(const ZString& sRequestName) const;
	bool HasActiveTransition(unsigned int iStateMachineID) const;
	float GetTransitionFraction(unsigned int iStateMachineID, unsigned int* pSourceNodeID, unsigned int* pDestinationNodeID) const;
	void SetCurrentStateForStateMachine(unsigned int nStateMachineNodeID, unsigned int nNewStateNodeID, bool bIgnoreIfActive);
	void SetDefaultStateForStateMachine(unsigned int nStateMachineNodeID, unsigned int nDefaultStateNodeID);
	unsigned int GetDefaultStateForStateMachine(unsigned int nStateMachineNodeID);
	bool FireWildCardTransition(unsigned int nStateMachineID, unsigned int nTransitionID, unsigned int nDestID, float fDuration);
	const MR::TriggeredEventsBuffer& GetTriggeredEvents() const;
	bool IsEventTriggered(unsigned int nEventId, float fMinWeight) const;
	MR::Rig* GetRig() const;
	static unsigned int GetRequestID(MR::NetworkDef* pNetworkDef, const ZString& sRequestName);
	unsigned int GetRequestID(const ZString& sRequestName) const;
	ZString GetRequestName(const unsigned int nRequestID) const;
	unsigned int GetNetworkIdOfTopLevelNodeInBlendTree(const ZString& sStateMachine, const ZString& sBlendTreeName) const;
	unsigned int GetNetworkIDForName(const char* sNodeName) const;
	unsigned int GetNetworkIDForName(const ZString& sNodeName) const;
	ZString GetNetworkNameForID(unsigned int nID) const;
	float GetEventFraction(unsigned int nNodeID) const;
	float GetEventFraction(const ZString& sNodeName) const;
	bool GetTimeFraction(const unsigned int nNodeId, SIOIAttribDataTime* pAttribData) const;
	bool SetTimeFraction(const unsigned int nNodeId, float fTimeFraction);
	bool IsNodeActive(const unsigned int nNodeId) const;
	int GetActiveNodeIds(unsigned int* pBuffer, int iBufferSize) const;
	int GetAnimIDFromMeshID(int nMeshID) const;
	void ExtractBoneSQVsFromAnimAtTimeFraction(const unsigned int nAnimNodeID, const int* pMeshID, SQV* pBuffer, unsigned int nNumBones, float fTimeFraction, bool bForceMirror, bool bForceSwapHandAttachers) const;
	SMatrix ExtractBoneMatPosFromAnimAtTimeFraction(const unsigned int nAnimNodeID, int nMeshID, float fTimeFraction) const;
	bool ExtractBoneFromAnimAtTimeFraction(const unsigned int nAnimNodeId, const unsigned int nRigIndex, float fTimeFraction, SMatrix& mResult) const;
	bool IsBoneAnimated(const unsigned int nAnimNodeId, const unsigned int nMrBoneIndex) const;
	unsigned int GetRootNodeIdInStateMachine(const unsigned int nSMId) const;
	float QueryAnimTimeFractionOfEvent(const unsigned int nAnimNodeId, const ZString& sEventTrackName, unsigned int nEventUserData) const;
	SMatrix43 GetAnimationTrajectoryDeltaRel(unsigned int iNode, float fFromTimeFrac, float fToTimeFrac, bool bMirror) const;
	bool ResetRequestInStateMachine(const unsigned int nStateMachineID, const unsigned int nRequestID);
	bool BackWardsPlay(unsigned int nAnimNodeId) const;
	float GetAnimStartFraction(unsigned int nAnimNodeId) const;
	float GetAnimEndFraction(unsigned int nAnimNodeId) const;
	int GetAnimNodeEvents(const unsigned int nAnimNodeId, const ZString& sEventTrackName, SIOIEvent* pEvents, const unsigned int nBufferSize) const;
	void SetPlayBackSpeedFactor(float fValue);
	float GetAnimTimeToNextEvent(unsigned int nNode, const ZString& sEventTrackName, unsigned int nEventUserData) const;
	bool IsNodeAnimationNode(unsigned int nNodeId) const;
	bool IsNodeSelectNode(unsigned int nNodeId) const;
	bool IsNodeSelectMatchEventsNode(unsigned int nNodeId) const;
	unsigned int GetMaxTransformCount() const;
	unsigned int GetCurrentTransformCount() const;
	unsigned int GetActiveNodeCount() const;
	unsigned int GetActiveNodes(unsigned int* pNodeIDsArray, unsigned int nArraySize) const;
	TArray<MR::Node*> GetActiveNodesOfType(unsigned int nNodeTypeID) const;
	bool EnableNodeDataBuffering(unsigned int* pNodeIDsArray, unsigned int numNodeIds, bool bEnable);
	unsigned int GetNodeBufferedDataTypeSize(unsigned int nodeID, MR::BufferableDataType type, char* clarificationString) const;
	bool GetNodeBufferedData(unsigned int nodeID, MR::BufferableDataType type, void* buffer, unsigned int bufferSize, char* clarificationString) const;
	MR::NodeStateMachine* GetNodeStateMachine(unsigned int nStateMachineNodeID) const;
	unsigned int GetNodeType(unsigned int nNodeID) const;
	unsigned int GetSampledNodes(unsigned int* pNodeIDsArray, unsigned int nArraySize) const;
	IVariationInstance* GetVariationInstance() const;
	void SetVariationInstance(IVariationInstance* pVariationInstance);
	bool GetMediatorUpdateFlag();
	void SetMediatorUpdateFlag(bool bUpdate);
	ZMorphemeNetworkInstance* GetChildNetwork(unsigned int nNodeId);
	TArray<ZMorphemeNetworkInstance*> GetAllChildNetworks() const;
	bool AttachChildNetworkWithOwnership(unsigned int nNodeId, const IChildNetworkEntity* pChildNetworkEntity);
	bool AttachChildNetwork(unsigned int nNodeId, ZMorphemeNetworkInstance* pChildNetwork);
	bool DetachChildNetwork(ZChildNetworkEntry* pEntry);
	bool DetachChildNetwork(ZMorphemeNetworkInstance* pChildNetwork);
	bool DetachChildNetwork(unsigned int nNodeId);
	void DetachAllChildNetworks();
	void SetCutSequenceData(const SCutSequenceData& cutSequenceData, ZString sSlotName);
	void SetMeshIDToRigIDMap(TArray<int>* pMeshIDToRigID);
	void SetBoneData(ZAnimationBoneData* pBoneData);
	void SetParent(ZMorphemeNetworkInstance* pParentNetwork);
	ZMorphemeNetworkInstance* GetParent() const;
	static unsigned int GetNodeID(MR::NetworkDef* pNetworkDef, const ZString& sName);
	unsigned int GetNodeID(const ZString& sName);
	ZString GetNodeName(unsigned int nNodeID);
	ZString GetFullNodePath(unsigned int nNodeID);
	unsigned int GetFirstNodeId(const ZString& sName) const;
	TArray<unsigned int> GetNodeIdList(const ZString& sName) const;
	static unsigned int GetChildNode(MR::NetworkDef* pNetworkDef, unsigned int nNodeID, const char* sName);
	unsigned int GetChildNode(unsigned int nNodeID, const char* sName);
	unsigned int GetChildNode(unsigned int nNodeID, const ZString& sName);
	unsigned int GetParentNode(unsigned int nNodeID);
	unsigned int GetParentNode(const ZString& sName);
	bool GetChildNodes(const MR::NodeDef* pNodeDef, TArray<ZString>& nodes);
	bool GetChildNodes(const MR::NodeDef* pNodeDef, TArray<unsigned int>& nodes);
	bool GetChildNodes(unsigned int nNodeID, TArray<ZString>& nodes);
	bool GetChildNodes(unsigned int nNodeID, TArray<unsigned int>& nodes);
	bool IsChildOf(unsigned int nNodeId, unsigned int nParentNodeId);
	const MR::Network* GetNetworkInternal() const;
	MR::Network* GetNetworkInternal();
	const SMorphemeData* GetMorphemeData() const;
	SMorphemeData* GetMorphemeData();
	bool GetNetworkHash(TArray<unsigned char>& hash) const;
	ZEntityRef GetOwnerEntity() const;
	static void AsyncUpdateFunction(const void* pData);
	MR::IAnimSource* GetAnimSource(unsigned int nNodeID) const;
	ZRuntimeResourceID GetAnimationRuntimeResourceID(unsigned int nNodeID) const;
	static const MR::NodeDef* LookupNodeInternal(MR::NetworkDef* pNetworkDef, const char* pszName, const char* pszSeparatorOrEnd, const MR::NodeDef* pStartNodeDef);
	static const MR::NodeDef* LookupNodeInternal(MR::NetworkDef* pNetworkDef, const char* pszName, const MR::NodeDef* pStartNodeDef);
	static const MR::NodeDef* LookupNodeInternal(MR::NetworkDef* pNetworkDef, unsigned int nNodeID);
	void GetAnimNodes(TArray<unsigned int>& Nodes, MR::NodeDef* pCurrentNode);
	SMatrix43 GetTrajectoryDeltaRel(const MR::IAnimSource* pAnimSource, float fFromTimeFrac, float fToTimeFrac, bool bMirror) const;
	void InterpolateControlParameters(float fDeltaTime);
	void StartNewNetworkUpdate(float fDeltaTime);
	ZChildNetworkEntry* GetChildNetworkEntry(unsigned int nNodeId);
	const ZChildNetworkEntry* GetChildNetworkEntry(unsigned int nNodeId) const;
	ZChildNetworkEntry* GetChildNetworkEntry(ZMorphemeNetworkInstance* pNetworkInstance);
	const ZChildNetworkEntry* GetChildNetworkEntry(ZMorphemeNetworkInstance* pNetworkInstance) const;
	void CheckPoolUsage() const;
};
