#pragma once

#include "ZStringBuilder.h"

class ZString;

class ZPath
{
public:
	enum
	{
		SEPARATOR = 47
	};

	ZStringBuilder m_value;

	static void RegisterType();
	ZPath(const ZString& rhs);
	ZPath(const ZPath& rhs);
	ZPath() = default;
	ZPath& operator=(const ZString& rhs);
	ZPath& operator=(const ZPath& rhs);
	bool operator==(const ZString& rhs) const;
	bool operator==(const ZPath& rhs) const;
	bool operator!=(const ZString& rhs) const;
	bool operator!=(const ZPath& rhs) const;
	bool operator<(const ZString& rhs) const;
	bool operator<(const ZPath& rhs) const;
	bool operator>(const ZString& rhs) const;
	bool operator>(const ZPath& rhs) const;
	int Length() const;
	bool IsEmpty() const;
	int Depth() const;
	void Clear();
	ZString ToString() const;
	const ZStringBuilder& GetStringBuilder() const;
	ZString GetName() const;
	ZPath GetChildPath() const;
	ZPath GetParentPath() const;
	ZPath& Append(const ZString& sPath);
	ZPath& Append(const ZPath& path);
	ZPath& Prepend(const ZString& sPath);
	ZPath& Prepend(const ZPath& path);
	static ZString Normalize(const ZString& sPath);
	~ZPath() = default;
};
