#ifndef CCM_PLUGIN_CONTEXT_HPP_INCLUDED
#define CCM_PLUGIN_CONTEXT_HPP_INCLUDED

#include "CCM/util.hpp"
#include "CCM/uuid.hpp"

enum CCMplugintype;

class CCMplugincontext
{
private:
    CCMplugincontext(uint32_t internal);

    uint32_t _internal;

    friend CCMplugincontext __ccmi__CreateContext(CCMplugintype type);

public:
    bool isValid();

    void error(CCMstring message, bool fatal);
    void warning(CCMstring message);
    void message(CCMstring message);
};

#endif
