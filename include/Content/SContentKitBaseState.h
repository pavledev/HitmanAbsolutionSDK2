#pragma once

struct STokenID;

struct SContentKitBaseState
{
	unsigned char m_iKitState;

	SContentKitBaseState() = default;
	~SContentKitBaseState() = default;
	bool IsLocked(const STokenID& id) const;
	bool IsLocked_LocalCheckOnly() const;
	unsigned char UnlockState_LocalCheckOnly() const;
	unsigned char UnlockState(const STokenID& id) const;
	void Unlock(bool viewed);
};
