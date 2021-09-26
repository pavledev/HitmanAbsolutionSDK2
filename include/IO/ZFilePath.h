#pragma once

#include "ZPath.h"
#include "ZStringBuilder.h"

class ZString;

class ZFilePath
{
public:
	enum
	{
		DIRECTORY_SEPARATOR = 47,
		EXTENSION_SEPARATOR = 46,
		DRIVE_SEPARATOR = 58
	};

	ZPath m_path;

	static void RegisterType();
	ZFilePath(const ZString& rhs);
	ZFilePath(const ZFilePath& rhs);
	ZFilePath() = default;
	ZFilePath& operator=(const ZFilePath& rhs);
	bool operator==(const ZFilePath& rhs) const;
	bool operator!=(const ZFilePath& rhs) const;
	bool operator<(const ZFilePath& rhs) const;
	bool operator>(const ZFilePath& rhs) const;
	unsigned int Length() const;
	bool IsEmpty() const;
	void Assign(const ZFilePath& path);
	bool StartsWith(const ZFilePath& path) const;
	bool IStartsWith(const ZFilePath& path) const;
	bool HasExtension(const ZString& ext) const;
	bool HasDirectory(const ZString& directory) const;
	bool IsAbsolute() const;
	int GetDirectoryCount() const;
	int GetDirectoryIndex(const ZString& directoryName) const;
	ZString GetExtension() const;
	ZFilePath GetDirectory() const;
	ZString GetDirectoryName(int index) const;
	ZFilePath ReplaceDirectoryName(int index, const ZString& newName) const;
	ZFilePath GetFileName() const;
	ZFilePath ReplaceFileName(const ZString& newName) const;
	ZFilePath RemoveExtension() const;
	ZFilePath ReplaceExtension(const ZString& ext) const;
	ZFilePath AddExtension(const ZString& ext) const;
	ZFilePath RemoveLeadingPath(const ZFilePath& path) const;
	ZFilePath IRemoveLeadingPath(const ZFilePath& path) const;
	ZFilePath IRemoveMatchingPath(const ZFilePath& path) const;
	ZFilePath RemoveLeadingSlash() const;
	ZFilePath Append(const ZFilePath& path) const;
	ZFilePath Prepend(const ZFilePath& path) const;
	ZString ToString() const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const ZString& sFormat) const;
	~ZFilePath() = default;
};
