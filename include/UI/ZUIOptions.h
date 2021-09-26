#pragma once

#include "IComponentInterface.h"
#include "ESaveLoadSlotStatus.h"
#include "_EUIOptionKey.h"
#include "ZEvent.h"
#include "THashMap.h"
#include "ZVariantRef.h"

class ZEventNull;
class ZHM5SaveData;
struct SComponentMapEntry;
struct STypeID;
template <class A, class B> class TDefaultHashMapPolicy;
template <class T> class alignas(8) ZDelegate;

class ZUIOptions : public IComponentInterface
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	template <class T>
	class Values
	{
	public:
		struct __declspec(novtable) ValueBase
		{
			ZEvent<T, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_Event;

			virtual ~ValueBase() = default;
			virtual T Get() = 0;
			virtual bool UnSet();
			virtual bool Set(T param1) = 0;
			virtual void Write(_EUIOptionKey key, ZHM5SaveData* data);
			virtual bool IsDefault();

			void RegisterForOptionChange(ZDelegate<void __cdecl(T)> callback);
			void UnregisterForOptionChange(ZDelegate<void __cdecl(T)> callback);
			ValueBase() = default;
		};

		THashMap<unsigned int, ValueBase*, TDefaultHashMapPolicy<unsigned int, ValueBase*>> m_values;

		~Values() = default;
		void AddValue(_EUIOptionKey optionKey, ValueBase* v);
		ValueBase*& operator[](_EUIOptionKey optionKey);
		bool LoadDefaults();
		void WriteData();
		Values() = default;
	};

	Values<float> m_FloatValues;
	Values<int> m_IntValues;
	Values<bool> m_BoolValues;
	bool m_bLoaded;
	bool m_bDirty;

	~ZUIOptions() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZUIOptions() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	bool Save();
	void LoadDefaults();
	void OnLoadDone(const ESaveLoadSlotStatus eStatus);
	void WriteData();
	int Int(unsigned int key);
	float Float(unsigned int key);
	bool Bool(unsigned int key);
	void SetInt(unsigned int key, int value);
	void SetFloat(unsigned int key, float value);
	void SetBool(unsigned int key, bool value);
	void ReadData();
};
