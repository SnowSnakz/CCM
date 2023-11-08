#ifndef CCM_HPP_INCLUDED
#define CCM_HPP_INCLUDED

#include "util.hpp"
#include "version.hpp"
#include "plugin/plugin.hpp"
#include "plugin/context.hpp"
#include "shapes/shape.hpp"

CCMversion ccmGetVersion();

CCMplugincontext ccmCreatePluginContext(CCMplugintype type);

#endif
