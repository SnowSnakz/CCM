#include "Editor.hpp"
#include "CCM.hpp"

int main(int argc, char** argv)
{
    // Get CCM API Version.
    CCMversion apiVersion = ccmGetVersion();

    // Print the CCM Version.
    std::cout << "CCM v" << apiVersion.major << "." << apiVersion.minor << "." << apiVersion.build << std::endl;

    // Create plugin context and load plugins.
    CCMplugincontext plugins = ccmCreatePluginContext(CCM_EDITOR_ONLY);
}
