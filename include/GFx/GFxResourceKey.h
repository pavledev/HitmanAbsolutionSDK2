#pragma once

class GFxResourceKey
{
public:
	enum KeyType
	{
		Key_None = 0,
		Key_Unique = 1,
		Key_File = 2,
		Key_Gradient = 3,
		Key_SubImage = 4
	};

	class __declspec(novtable) KeyInterface
	{
	public:
		virtual ~KeyInterface() = default;
		virtual void AddRef(void* param1) = 0;
		virtual void Release(void* param1) = 0;
		virtual KeyType GetKeyType(void* param1) const = 0;
		virtual unsigned int GetHashCode(void* param1) const = 0;
		virtual bool KeyEquals(void* param1, const GFxResourceKey& fxResourceKey) = 0;

		KeyInterface() = default;
	};

	class HashOp
	{
	};

	KeyInterface* pKeyInterface;
	void* hKeyData;

	GFxResourceKey() = default;
	~GFxResourceKey() = default;
};
