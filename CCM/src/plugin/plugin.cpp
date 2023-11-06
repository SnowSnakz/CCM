#include "plugin/plugin.hpp"

CCMplugin::CCMplugin(icu::UnicodeString name, icu::UnicodeString description, icu::UnicodeString vendor, CCMversion version, CCMplugintype pluginType) 
    : _name(name), _description(description), _vendor(vendor), _version(version), _pluginType(pluginType)
{
}