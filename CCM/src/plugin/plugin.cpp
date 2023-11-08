#include "plugin/plugin.hpp"

CCMplugin::CCMplugin(CCMstring name, CCMstring description, CCMstring vendor, CCMversion version, CCMplugintype pluginType, CCMuuid uniqueID) 
    : _name(name), _description(description), _vendor(vendor), _version(version), _pluginType(pluginType), _uniqueID(uniqueID)
{
}

CCMstring CCMplugin::getName()
{
    return _name;
}

CCMstring CCMplugin::getDescription()
{
    return _description;
}

CCMstring CCMplugin::getVendor()
{
    return _vendor;
}

CCMversion CCMplugin::getVersion()
{
    return _version;
}

CCMplugintype CCMplugin::getPluginType()
{
    return _pluginType;
}

CCMuuid CCMplugin::getUniqueID()
{
    return _uniqueID;
}