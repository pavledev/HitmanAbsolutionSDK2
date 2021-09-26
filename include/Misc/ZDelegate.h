#pragma once

template <class T>
class alignas(8) ZDelegate
{
public:
	struct SStaticInvoke
	{
	};

	T* m_mfp;

	ZDelegate() = default;
	~ZDelegate() = default;
	//void operator()(const ZRuntimeResourceID& a0) const;
	bool IsValid() const;
	bool operator==(const ZDelegate& rhs) const;
};
