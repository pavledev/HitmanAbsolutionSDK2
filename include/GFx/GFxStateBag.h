#pragma once

#include "GFxFileConstants.h"
#include "GPtr.h"

class GFxRenderConfig;
class GFxLog;
class GFxFSCommandHandler;
class GFxExternalInterface;
class GFxFileOpenerBase;
class GFxImageCreator;
class GFxFontCacheManager;
class GFxFontLib;
class GFxFontMap;
class GFxTaskManager;
class GFxPNGSupportBase;

class GFxStateBag : public GFxFileConstants
{
public:
	virtual ~GFxStateBag() = default;

	void SetRenderConfig(GFxRenderConfig* pri);
	void SetLog(GFxLog* plog);
	void SetFSCommandHandler(GFxFSCommandHandler* ps);
	void SetExternalInterface(GFxExternalInterface* p);
	void SetFileOpener(GFxFileOpenerBase* ptr);
	void SetImageCreator(GFxImageCreator* ptr);
	GPtr<GFxFontCacheManager> GetFontCacheManager() const;
	void SetFontLib(GFxFontLib* pri);
	void SetFontMap(GFxFontMap* ptr);
	void SetTaskManager(GFxTaskManager* ptr);
	void SetPNGSupport(GFxPNGSupportBase* ptr);
	GFxStateBag() = default;
};
