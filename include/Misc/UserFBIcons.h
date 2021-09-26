#pragma once

#include "TEntityRef.h"
#include "ZGameTime.h"
#include "float4.h"
#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZSpatialEntity;
class ZComponentCreateInfo;
struct STypeID;

class UserFBIcons
{
public:
	class __declspec(novtable) IHM5TimerToOSD
	{
	public:
		virtual void OSDTimerFireTimeOut() = 0;
		virtual float OSDTimerGetTimer() const = 0;
		virtual void OSDTimerStart() = 0;
		virtual void OSDTimerStop() = 0;
		virtual unsigned int OSDTimerGetHash() const = 0;
		virtual const float4 OSDTimerGet3DPos() const = 0;
		virtual ~IHM5TimerToOSD() = default;

		IHM5TimerToOSD() = default;
	};

	struct STimerToOSDElement
	{
		TEntityRef<IHM5TimerToOSD> m_Key;
		ZGameTime m_tStarted;
		ZGameTime m_tEnding;
		char m_iDispTextIndex;

		STimerToOSDElement() = default;
		bool operator==(const TEntityRef<IHM5TimerToOSD>& other);
		bool operator!=(const TEntityRef<IHM5TimerToOSD>& other);
		void SetData(const TEntityRef<IHM5TimerToOSD>& key, ZGameTime started, ZGameTime ending, char iDispTextIndex);
		void SetData(const STimerToOSDElement& src);
		void Clear();
		bool IsNull() const;
		~STimerToOSDElement() = default;
	};

	class ZHM5TimerToOSDEntity : public ZEntityImpl, public IHM5TimerToOSD
	{
	public:
		enum
		{
			COPYABLE = 0,
			ASSIGNABLE = 0
		};

		float m_fTimer;
		TEntityRef<ZSpatialEntity> m_rWorldPosEntity;

		static SComponentMapEntry s_componentMap[0];

		~ZHM5TimerToOSDEntity() override = default;
		ZVariantRef GetVariantRef() const override;
		int AddRef() override;
		int Release() override;
		void* QueryInterface(STypeID* iid) override;

		void OSDTimerFireTimeOut() override;
		float OSDTimerGetTimer() const override;
		void OSDTimerStart() override;
		void OSDTimerStop() override;
		unsigned int OSDTimerGetHash() const override;
		const float4 OSDTimerGet3DPos() const override;

		ZHM5TimerToOSDEntity() = default;
		static void RegisterType();
		ZHM5TimerToOSDEntity(ZComponentCreateInfo& info);
		void OnStart();
		void OnStop();
	};
};
