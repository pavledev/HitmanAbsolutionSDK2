#pragma once

class __declspec(novtable) ISharedPointerTarget
{
public:
	virtual ~ISharedPointerTarget() = default;
	virtual void AddReference() const = 0;
	virtual void RemoveReference() const = 0;
	virtual unsigned int GetRefCount() const = 0;

	ISharedPointerTarget(const ISharedPointerTarget& __that);
	ISharedPointerTarget() = default;
	ISharedPointerTarget& operator=(const ISharedPointerTarget& __that);
};
