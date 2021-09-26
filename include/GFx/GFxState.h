#pragma once

#include "GRefCountBase.h"

class GFxState : public GRefCountBase<GFxState, 2>
{
public:
	enum StateType
	{
		State_None = 0,
		State_RenderConfig = 1,
		State_RenderStats = 2,
		State_Translator = 3,
		State_Log = 4,
		State_ImageLoader = 5,
		State_ActionControl = 6,
		State_UserEventHandler = 7,
		State_FSCommandHandler = 8,
		State_ExternalInterface = 9,
		State_FileOpener = 10,
		State_URLBuilder = 11,
		State_ImageCreator = 12,
		State_ParseControl = 13,
		State_ProgressHandler = 14,
		State_ImportVisitor = 15,
		State_MeshCacheManager = 16,
		State_FontPackParams = 17,
		State_FontCacheManager = 18,
		State_FontLib = 19,
		State_FontProvider = 20,
		State_FontMap = 21,
		State_GradientParams = 22,
		State_TaskManager = 23,
		State_TextClipboard = 24,
		State_TextKeyMap = 25,
		State_PreprocessParams = 26,
		State_IMEManager = 27,
		State_XMLSupport = 28,
		State_JpegSupport = 29,
		State_ZlibSupport = 30,
		State_FontCompactorParams = 31,
		State_ImagePackerParams = 32,
		State_PNGSupport = 33,
		State_Audio = 34,
		State_Video = 35,
		State_TestStream = 36,
		State_SharedObject = 37,
		State_LocSupport = 38
	};

	StateType SType;

	~GFxState() override = default;

	GFxState() = default;
	GFxState(StateType st);
};
