#ifndef CCM_PLUGIN_HPP_INCLUDED
#define CCM_PLUGIN_HPP_INCLUDED

#include "util.hpp"
#include "uuid.hpp"
#include "version.hpp"

class CCMplugincontext;

enum CCMplugintype
{
    // The plugin affects both the editor and the runtime.
    CCM_EDITOR_AND_RUNTIME,

    // The plugin only affects the editor.
    CCM_EDITOR_ONLY,

    // The plugin only affects the runtime.
    CCM_RUNTIME_ONLY
};

class CCMplugin
{
private:
    CCMstring _name;
    CCMstring _description;
    CCMstring _vendor;
    CCMversion _version;
    CCMplugintype _pluginType;
    CCMuuid _uniqueID;

    friend class CCMplugincontext;

protected:
    CCMplugin(CCMstring name, CCMstring description, CCMstring vendor, CCMversion version, CCMplugintype pluginType);

    // Should return true if the current version of the plugin is compatible with the specified version.
    virtual bool isCompatible(CCMversion version) = 0;

    // Used to perform plugin setup.
    virtual void onReady(CCMplugincontext ctx) = 0;

public:
    CCMstring getName();
    CCMstring getDescription();
    CCMstring getVendor();
    CCMversion getVersion();
    CCMplugintype getPluginType();
    CCMuuid getUniqueID();
};

#endif
