#pragma once

#include "GRefCountBaseStatImpl.h"

template<class A, int B>
class GRefCountBase : GRefCountBaseStatImpl<GRefCountImpl, B>
{

};
