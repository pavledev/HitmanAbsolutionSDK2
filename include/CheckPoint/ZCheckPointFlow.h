#pragma once

class ZCheckPointFlow
{
public:
	ZCheckPointFlow() = default;
	~ZCheckPointFlow() = default;
	void RestartLevel();
	void RestartCheckPoint();
	void LevelEnded();
	bool ContinueToNextLevel() const;
};
