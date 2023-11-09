#include "CCM/CCM.hpp"

CCMversion ccmGetVersion()
{
    // Current version is 1.0.0
    return { CCM_VMAJOR, CCM_VMINOR, CCM_VBUILD };
}

// Defined in src/plugin/context.cpp
extern CCMplugincontext __ccmi__CreateContext(CCMplugintype type);
CCMplugincontext ccmCreatePluginContext(CCMplugintype type)
{
    return __ccmi__CreateContext(type);
}
