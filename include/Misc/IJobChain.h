#pragma once

class IJob;

class __declspec(novtable) IJobChain
{
public:
	virtual ~IJobChain() = default;
	virtual IJob* CreateJob(unsigned int param1, unsigned int param2) = 0;
	virtual IJob* CreateJobInPlace(void* pPlacement, unsigned int nNumDataBuffers, unsigned int nUserBufferSize);
	virtual unsigned long long AddJob(IJob* job) = 0;
	virtual unsigned long long AddJobsBulk(IJob** pJobs, unsigned int nNumJobs);
	virtual unsigned long long AddFlush() = 0;
	virtual void WaitAllDone() = 0;

	IJobChain() = default;
};
