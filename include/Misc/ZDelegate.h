#pragma once

#include "ISequenceEntity.h"

//template<class A, class B>
//auto Func(const A&, const B&)
//{
//
//};
//
//template<typename Func>
//class ZDelegate
//{
//    void(__thiscall* m_mfp)(void* this, ISequenceEntity*);
//    //void(__thiscall* m_mfp)(ZGenericMemberFunctionTarget* this, ISequenceEntity*);
//};

//template<class T>
//class ZDelegate
//{
//	void(__thiscall* mfp)(void* this, T);
//};

//template<class T>
//class ZDelegate
//{
//    template<typename... Args>
//    auto operator()(Args&&... args) const
//    {
//        return Func(std::forward<Args>(args)...);
//    }
//};

//template<class T>
//class ZDelegate
//{
//	(T*)msp;
//};

template<class T>
class ZDelegate
{
public:
	T* m_mfp;
};
