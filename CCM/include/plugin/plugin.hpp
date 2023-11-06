#ifndef CCM_PLUGIN_HPP_INCLUDED
#define CCM_PLUGIN_HPP_INCLUDED

#include "CCM.hpp"

enum CCMpluginmode
{
    // The plugin is optional on the specified platform.
    CCM_OPTIONAL,

    // The plugin is required on the specified platform.
    CCM_REQUIRED
};

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
    icu::UnicodeString _name;
    icu::UnicodeString _description;
    icu::UnicodeString _vendor;

    CCMversion _version;
    CCMplugintype _pluginType;

protected:
    CCMplugin(icu::UnicodeString name, icu::UnicodeString description, icu::UnicodeString vendor, CCMversion version, CCMplugintype pluginType);
};



#endif
