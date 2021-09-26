#pragma once

class IJobProgram;

class __declspec(novtable) IJob
{
public:
	enum EReadBufferType
	{
		DATA_TYPE_READ = 0,
		DATA_TYPE_READ_WRITE = 1
	};

	virtual bool IsJobDone() const = 0;
	virtual void WaitJobDone() const = 0;
	virtual unsigned long long GetBookmark() const;
	virtual void SetReadBuffer(unsigned int param1, const void* param2, unsigned int param3, EReadBufferType readBufferType) = 0;
	virtual void SetWriteBuffer(void* param1, unsigned int param2) = 0;
	virtual void SetCachedData(unsigned int param1, const void* param2, unsigned int param3) = 0;
	virtual void SetUserData(const void* param1, unsigned int param2) = 0;
	virtual void SetScratchSize(unsigned int param1) = 0;
	virtual void SetJobProgram(IJobProgram* jobProgram, unsigned int param2) = 0;
	virtual void* GetReadBuffer(unsigned int param1) const = 0;
	virtual unsigned int GetReadBufferSize(unsigned int param1) const = 0;
	virtual void* GetWriteBuffer() const = 0;
	virtual unsigned int GetWriteBufferSize() const = 0;
	virtual const void* GetCachedData(unsigned int param1) const = 0;
	virtual unsigned int GetCachedDataSize(unsigned int param1) const = 0;
	virtual const void* GetUserData() const = 0;
	virtual ~IJob() = default;

	IJob() = default;
};
