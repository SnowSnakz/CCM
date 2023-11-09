#include "Editor.hpp"

int main(int argc, char** argv)
{
    const char** lastError = new const char*[1];

    // TODO: Load user preferences.

    // Get CCM API Version.
    CCMversion apiVersion = ccmGetVersion();

    // Print the CCM Version.
    std::cout << "Using CCM v" << ((int)apiVersion.major) << "." << ((int)apiVersion.minor) << "." << ((int)apiVersion.build) << std::endl;

    // Create plugin context and load plugins.
    CCMplugincontext plugins = ccmCreatePluginContext(CCM_EDITOR_ONLY);

    // Load plugins from plugin folder.
    // TODO: Load the plugins.

    // Initialize GLFW and OpenGL
    if(!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW." << std::endl;

        int error = glfwGetError(lastError);
        if(error != GLFW_NO_ERROR)
        {
            std::cerr << (*lastError) << std::endl;
        }

        return -1;
    }

    // Setup window hints.
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // Start out invisible.
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); // Enable resize.

    // Attempt to create a new window.
    GLFWwindow* window = glfwCreateWindow(800, 600, "CCM Model Editor", nullptr, nullptr);
    if(window == nullptr)
    {
        std::cerr << "Failed to create a window." << std::endl;
        
        int error = glfwGetError(lastError);
        if(error != GLFW_NO_ERROR)
        {
            std::cerr << (*lastError) << std::endl;
        }

        glfwTerminate();

        return -1;
    }

    // Maximise the window.
    glfwMaximizeWindow(window);

    // Make the created window the current context on this thread.
    glfwMakeContextCurrent(window);
    
    // Attempt to load OpenGL.
    int glVersion = gladLoadGL(glfwGetProcAddress);
    if(glVersion == 0)
    {
        std::cerr << "Failed to load OpenGL." << std::endl;

        glfwTerminate();

        return -1;
    }

    int glMajor = GLAD_VERSION_MAJOR(glVersion);
    int glMinor = GLAD_VERSION_MINOR(glVersion);

    // Print OpenGL Version.
    std::cout << "Using OpenGL " << glMajor << "." << glMinor << std::endl;

    // TODO: Use glVersion to determine API compatibility.

    // Enable all loaded plugins.
    // plugins->enableAll();

    // Make the window visible.
    glfwShowWindow(window);

    // Enable V-Sync
    glfwSwapInterval(1);

    // Run the editor loop.
    while(!glfwWindowShouldClose(window))
    {
        // Wait (up to 5 seconds) for and execute events.
        glfwPollEvents();

        // Update editor state.

        // Redraw invalidated surfaces.

        // Display the new frame.
        glfwSwapBuffers(window);
    }

    // Clean up.
    glfwTerminate();

    return 0;
}
