#ifndef CCM_HPP_INCLUDED
#define CCM_HPP_INCLUDED

#include "CCM/util.hpp"
#include "CCM/version.hpp"
#include "CCM/plugin/plugin.hpp"
#include "CCM/plugin/context.hpp"
#include "CCM/shapes/shape.hpp"

CCMversion ccmGetVersion();

CCMplugincontext ccmCreatePluginContext(CCMplugintype type);

#endif
