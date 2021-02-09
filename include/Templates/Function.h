#pragma once

namespace Function
{
    template <unsigned int address, typename... Args>
    void Call(Args... args)
    {
        reinterpret_cast<void(__cdecl*)(Args...)>(address)(args...);
    }

    template <typename... Args>
    void Call(unsigned int address, Args... args)
    {
        reinterpret_cast<void(__cdecl*)(Args...)>(address)(args...);
    }

    template <unsigned int address, typename... Args>
    void StdCall(Args... args)
    {
        reinterpret_cast<void(__stdcall*)(Args...)>(address)(args...);
    }

    template <typename... Args>
    void StdCall(unsigned int address, Args... args)
    {
        reinterpret_cast<void(__stdcall*)(Args...)>(address)(args...);
    }

    template <typename Ret, unsigned int address, typename... Args>
    Ret CallAndReturn(Args... args)
    {
        return reinterpret_cast<Ret(__cdecl*)(Args...)>(address)(args...);
    }

    template <typename Ret, typename... Args>
    Ret CallAndReturn(unsigned int address, Args... args)
    {
        return reinterpret_cast<Ret(__cdecl*)(Args...)>(address)(args...);
    }

    template <typename Ret, unsigned int address, typename... Args>
    Ret StdCallAndReturn(Args... args)
    {
        return reinterpret_cast<Ret(__stdcall*)(Args...)>(address)(args...);
    }

    template <typename Ret, typename... Args>
    Ret StdCallAndReturn(unsigned int address, Args... args)
    {
        return reinterpret_cast<Ret(__stdcall*)(Args...)>(address)(args...);
    }

    template <unsigned int address, typename C, typename... Args>
    void FastCall(C _this, Args... args)
    {
        reinterpret_cast<void(__fastcall*)(C, Args...)>(address)(_this, args...);
    }

    template <typename C, typename... Args>
    void FastCall(unsigned int address, C _this, Args... args)
    {
        reinterpret_cast<void(__fastcall*)(C, Args...)>(address)(_this, args...);
    }

    template <unsigned int address, typename C, typename... Args>
    void CallMethod(C _this, Args... args)
    {
        reinterpret_cast<void(__thiscall*)(C, Args...)>(address)(_this, args...);
    }

    template <typename C, typename... Args>
    void CallMethod(unsigned int address, C _this, Args... args)
    {
        reinterpret_cast<void(__thiscall*)(C, Args...)>(address)(_this, args...);
    }

    template <typename Ret, unsigned int address, typename C, typename... Args>
    Ret FastCallAndReturn(C _this, Args... args)
    {
        return reinterpret_cast<Ret(__fastcall*)(C, Args...)>(address)(_this, args...);
    }

    template <typename Ret, typename C, typename... Args>
    Ret FastCallAndReturn(unsigned int address, C _this, Args... args)
    {
        return reinterpret_cast<Ret(__fastcall*)(C, Args...)>(address)(_this, args...);
    }

    template <typename Ret, unsigned int address, typename C, typename... Args>
    Ret CallMethodAndReturn(C _this, Args... args)
    {
        return reinterpret_cast<Ret(__thiscall*)(C, Args...)>(address)(_this, args...);
    }

    template <typename Ret, typename C, typename... Args>
    Ret CallMethodAndReturn(unsigned int address, C _this, Args... args)
    {
        return reinterpret_cast<Ret(__thiscall*)(C, Args...)>(address)(_this, args...);
    }

    template <unsigned int tableIndex, typename C, typename... Args>
    void CallVirtualMethod(C _this, Args... args)
    {
        reinterpret_cast<void(__thiscall*)(C, Args...)>((*reinterpret_cast<void***>(_this))[tableIndex])(_this, args...);
    }

    template <typename Ret, unsigned int tableIndex, typename C, typename... Args>
    Ret CallVirtualMethodAndReturn(C _this, Args... args)
    {
        return reinterpret_cast<Ret(__thiscall*)(C, Args...)>((*reinterpret_cast<void***>(_this))[tableIndex])(_this, args...);
    }
}