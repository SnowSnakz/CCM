#include "CCM.hpp"

CCMversion ccmGetVersion()
{
    // Current version is 1.0.0
    return { 1, 0, 0 };
}

// Defined in src/plugin/context.cpp
extern CCMplugincontext __ccmi__CreateContext();
CCMplugincontext ccmCreatePluginContext()
{
    return __ccmi__CreateContext();
}
