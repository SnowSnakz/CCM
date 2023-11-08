#include <iostream>
#include "CCMplugin.hpp"

bool _MAIN_CLASS::isCompatible(CCMversion version)
{
    // This function is called when a CCM file that uses this plugin is loaded.
    // If the CCM file specifies that this plugin is in use, this function makes sure that the current
    // version of the plugin is fully compatible with the version that was specified in the CCM file.

    // No backwards or forwards compatibility. (this plugin can only work on files that exactly matches the current version of the plugin.)
    return version == getVersion();

    // Backwards Compatible (this plugin can work on files that require an older version of the plugin.)
    // return version <= getVersion();

    // Forwards Compatible (this plugin can work on files that require a more updated version of the plugin. NOT RECOMMENDED!)
    // return version >= getVersion();

    // Full Compatibility (this plugin can work on files that require any version of the plugin, newer or older. NOT RECOMMENDED!)
    // return true;
}

void _MAIN_CLASS::onReady(CCMplugincontext ctx) 
{
    // This function is called by CCMplugincontext when all plugins have been loaded and CCM is ready for use.

    // Display a simple message.
    CCMstring message = ccmMakeStringUTF8("Hello from onReady()");
    ctx.message(message);
}

// You can implement your methods below:

// defined in PluginBody.inc
void _MAIN_CLASS::doSomething() 
{
    // Increment someInt. (Defined in PluginBody.inc)
    someInt++;

    // Print value of someInt
    std::cout << "Value of someInt: " << someInt << std::endl;
}
