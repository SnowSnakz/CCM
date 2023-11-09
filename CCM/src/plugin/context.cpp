#include "CCM.hpp"

#include "plugin/context.hpp"
#include "plugin/plugin.hpp"

const size_t _CCM_MAX_PLUGIN_CONTEXTS = 8;

class CCMIplugincontext
{
public:
    static CCMIplugincontext* contexts[_CCM_MAX_PLUGIN_CONTEXTS];

    bool isValid() 
    {
        // TODO: Check if disposed.
        return true;
    }
};

int current = 0;
CCMplugincontext __ccmi__CreateContext(CCMplugintype type)
{
    // If 8 contexts have already been created...
    if(current >= _CCM_MAX_PLUGIN_CONTEXTS)
    {
        // Check if one was disposed
        for(int i = 0; i < _CCM_MAX_PLUGIN_CONTEXTS; i++)
        {
            // Check if slot was disposed.
            if(CCMIplugincontext::contexts[i]->isValid())
                continue;

            // Free the memory for the internal context instance at the free slot.
            delete CCMIplugincontext::contexts[i];

            // Reuse disposed context slot.
            return CCMplugincontext(i + 1);
        }

        // If not, set the last error. (Uncomment the following line when supported.)
        // ccmSetLastError(CCM_ERROR_TOO_MANY_CONTEXTS);

        // Return a "null" context.
        return CCMplugincontext(0);
    }
    
    // Create a new context using the next available internal context.
    return CCMplugincontext(++current);
}

CCMplugincontext::CCMplugincontext(uint32_t internal) 
    : _internal(internal)
{
    // Verify that internal is not "null"
    if(internal == 0)
        return;

    // Create internal plugin context and assign it.
    CCMIplugincontext* internalContext = new CCMIplugincontext();
    CCMIplugincontext::contexts[internal - 1] = internalContext;
}

bool CCMplugincontext::isValid()
{
    if(_internal == 0)
        return false;

    // TODO: Check if context is disposed.
    return CCMIplugincontext::contexts[_internal]->isValid();
}
