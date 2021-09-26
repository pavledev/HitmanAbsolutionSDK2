#pragma once

class ZMorphemeNetworkInstance;

struct ZChildNetworkEntry
{
	ZMorphemeNetworkInstance* m_pNetworkInstance;
	unsigned int m_nNodeID;
	int m_nNetworkId;

	ZChildNetworkEntry(unsigned int nNodeID);
	ZChildNetworkEntry() = default;
	~ZChildNetworkEntry() = default;
	bool IsOwner() const;
};
