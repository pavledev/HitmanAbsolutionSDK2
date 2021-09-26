#pragma once

#include "TArrayFixedHeap.h"
#include "SKnownEntity.h"
#include "TFixedArray.h"
#include "TRefCountPtrArg.h"

class ZKnownEntityContainer
{
public:
	class ZActorKnownEntitiesEnumerator
	{
	public:
		SKnownEntity* pCurrent;
		unsigned short current;
		unsigned short end;

		bool MoveNext();
		TRefCountPtrArg<SKnownEntity> Current();
	};

	struct SLink
	{
		unsigned short prev;
		unsigned short next;
	};

	struct SHashNode
	{
		union 
		{
			unsigned short actorId;
			unsigned short nextFreeHashNode;
		};

		unsigned short entityId;
		unsigned short padding;
		unsigned short knownEntityId;
		SLink sameHash;
		SLink sameActor;
	};

	unsigned int m_nNumAllocatedKnownEntities;
	TArrayFixedHeap<SKnownEntity, 3072> m_KnownEntities;
	TFixedArray<SLink, 4096> m_hashLinks;
	TFixedArray<SLink, 600> m_actorLinks;
	TFixedArray<SHashNode, 4096> m_hashTable;
	unsigned int m_nFirstFreeHashNode;

	static const unsigned int MAX_KNOWN_ENTITIES;
	static const unsigned int HASH_TABLE_SIZE;

	ZKnownEntityContainer(const ZKnownEntityContainer& __that);
	ZKnownEntityContainer() = default;
	SKnownEntity* AllocateKnownEntity();
	void FreeKnownEntity(SKnownEntity* pEntity);
	unsigned int GetNumAllocatedKnownEntities();
	bool CanAllocateKnownEntity();
	void DumpAllocatedKnownEntities();
	TRefCountPtrArg<SKnownEntity> GetKnownEntity(unsigned int actorId, unsigned int entityId);
	ZActorKnownEntitiesEnumerator GetKnownEntities(unsigned int actorIndex);
	void RemoveAllKnownEntities(unsigned int actorId);
	bool RemoveKnownEntity(unsigned int actorId, unsigned int entityId);
	void AddKnownEntity(unsigned int actorId, unsigned int entityId, SKnownEntity* pKnownEntity);
	unsigned int GetKnownEntityIndex(SKnownEntity* pKnownEntity);
	SKnownEntity* GetKnownEntityFromIndex(unsigned int nIndex);
	unsigned int fnv1a(unsigned int input, unsigned int hash);
	unsigned int Hash(unsigned int actorId, unsigned int entityId);
	unsigned short GetLinkIndex(SLink* p);
	SLink* GetLink(unsigned int index);
	SHashNode* GetHashNode(unsigned int index);
	SHashNode* AllocHashNode();
	void FreeHashNode(SHashNode* pHashNode);
	void ListInsert(SLink& newNode, SLink& after);
	void ListRemove(SLink& node);
	void RemoveHashNode(SHashNode* pNode);
	~ZKnownEntityContainer() = default;
};
