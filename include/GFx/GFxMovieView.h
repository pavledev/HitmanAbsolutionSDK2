#pragma once

#include "GFxMovie.h"
#include "GFxStateBag.h"
#include "GPoint.h"
#include "GRect.h"
#include "GFxMovieDef.h"

class GViewport;
class GMatrix3D;
class GColor;
class GMatrix2D;
class GStatBag;
class GMemoryHeap;
class GFxEvent;
class GFxValue;
template <class T> class GPoint3;

class __declspec(novtable) GFxMovieView : public GFxMovie, public GFxStateBag
{
public:
	enum ScaleModeType
	{
		SM_NoScale = 0,
		SM_ShowAll = 1,
		SM_ExactFit = 2,
		SM_NoBorder = 3
	};

	enum AlignType
	{
		Align_Center = 0,
		Align_TopCenter = 1,
		Align_BottomCenter = 2,
		Align_CenterLeft = 3,
		Align_CenterRight = 4,
		Align_TopLeft = 5,
		Align_TopRight = 6,
		Align_BottomLeft = 7,
		Align_BottomRight = 8
	};

	enum HE_ReturnValueType
	{
		HE_NotHandled = 0,
		HE_Handled = 1,
		HE_NoDefaultAction = 2,
		HE_Completed = 3
	};

	enum HitTestType
	{
		HitTest_Bounds = 0,
		HitTest_Shapes = 1,
		HitTest_ButtonEvents = 2,
		HitTest_ShapesNoInvisible = 3
	};

	~GFxMovieView() override = default;
	virtual bool GetVariable(GFxValue* fxValue, const char* param2) const = 0;
	virtual bool Invoke(const char* param1, GFxValue* fxValue, const char* param3, ...) = 0;
	virtual bool Invoke(const char* param1, GFxValue* fxValue, const GFxValue* fxValue3, unsigned int param4) = 0;
	virtual bool InvokeArgs(const char* param1, GFxValue* fxValue, const char* param3, char* param4) = 0;
	virtual void SetViewport(const GViewport& viewport) = 0;
	virtual void GetViewport(GViewport* viewport) const = 0;
	virtual void SetViewScaleMode(ScaleModeType scaleModeType) = 0;
	virtual ScaleModeType GetViewScaleMode() const = 0;
	virtual void SetViewAlignment(AlignType alignType) = 0;
	virtual AlignType GetViewAlignment() const = 0;
	virtual GRect<float> GetVisibleFrameRect() const = 0;
	virtual void SetPerspective3D(const GMatrix3D& matrix3D) = 0;
	virtual void SetView3D(const GMatrix3D& matrix3D) = 0;
	virtual GRect<float> GetSafeRect() const = 0;
	virtual void SetSafeRect(const GRect<float>& rect) = 0;
	virtual void Restart() = 0;
	virtual float Advance(float param1, unsigned int param2) = 0;
	virtual void Display() = 0;
	virtual void DisplayPrePass() = 0;
	virtual void SetPause(bool param1) = 0;
	virtual bool IsPaused() const = 0;
	virtual void SetBackgroundColor(const GColor color) = 0;
	virtual void SetBackgroundAlpha(float param1) = 0;
	virtual float GetBackgroundAlpha() const = 0;
	virtual unsigned int HandleEvent(const GFxEvent& fxEvent) = 0;
	virtual void GetMouseState(unsigned int param1, float* param2, float* param3, unsigned int* param4) = 0;
	virtual void NotifyMouseState(float param1, float param2, unsigned int param3, unsigned int param4) = 0;
	virtual bool HitTest(float param1, float param2, HitTestType hitTestType, unsigned int param4) = 0;
	virtual bool HitTest3D(GPoint3<float>* point3, float param2, float param3, unsigned int param4) = 0;
	virtual void SetExternalInterfaceRetVal(const GFxValue& fxValue) = 0;
	virtual void* GetUserData() const = 0;
	virtual void SetUserData(void* param1) = 0;
	virtual bool AttachDisplayCallback(const char* param1, void (*param2)(void* param1), void* param3) = 0;
	virtual bool IsMovieFocused() const = 0;
	virtual bool GetDirtyFlag(bool param1) = 0;
	virtual void SetMouseCursorCount(unsigned int param1) = 0;
	virtual unsigned int GetMouseCursorCount() const = 0;
	virtual void SetControllerCount(unsigned int param1) = 0;
	virtual unsigned int GetControllerCount() const = 0;
	virtual void GetStats(GStatBag* statBag, bool param2) = 0;
	virtual GMemoryHeap* GetHeap() const = 0;
	virtual void ForceCollectGarbage() = 0;
	virtual GRect<float> TranslateToScreen(const GRect<float>& rect, GMatrix2D matrix2D) = 0;
	virtual GPoint<float> TranslateToScreen(const GPoint<float>& point, GMatrix2D matrix2D) = 0;
	virtual bool TranslateLocalToScreen(const char* param1, const GPoint<float>& point, GPoint<float>* point3, GMatrix2D matrix2D) = 0;
	virtual bool SetControllerFocusGroup(unsigned int param1, unsigned int param2) = 0;
	virtual unsigned int GetControllerFocusGroup(unsigned int param1) const = 0;
	virtual GFxMovieDef::MemoryContext* GetMemoryContext() const = 0;
	virtual void Release() = 0;

	GFxMovieView() = default;
};
