#ifndef CCM_PLUGIN_CONTEXT_HPP_INCLUDED
#define CCM_PLUGIN_CONTEXT_HPP_INCLUDED

#include "util.hpp"
#include "uuid.hpp"

class CCMplugincontext
{
private:
    uint32_t _internal;

public:
    bool getPluginStatus(CCMuuid pluginID, CCMversion version, bool isRequired);

    void error(CCMstring message, bool fatal);
    void warning(CCMstring message);
    void message(CCMstring message);
};

#endif
