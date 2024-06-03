#include <GLFW/glfw3.h>
#include <iostream>

void joystick_callback(int jid, int event) {
    if (event == GLFW_CONNECTED) {
        std::cout << "Joystick connected: " << glfwGetJoystickName(jid) << std::endl;
    } else if (event == GLFW_DISCONNECTED) {
        std::cout << "Joystick disconnected: " << glfwGetJoystickName(jid) << std::endl;
    }
}

int main() {
    if (!glfwInit()) {
        // Initialization failed
        return -1;
    }

    // Set joystick callback
    glfwSetJoystickCallback(joystick_callback);

    // Check if joystick is present
    if (!glfwJoystickPresent(GLFW_JOYSTICK_1)) {
        std::cerr << "Joystick not found!" << std::endl;
        glfwTerminate();
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Joystick Test", NULL, NULL);
    if (!window) {
        // Window creation failed
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll events
        glfwPollEvents();

        // Get joystick axes
        int count;
        const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);
        if (axes != NULL && count >= 2) {
            float xAxis = axes[0];
            float yAxis = axes[1];
            std::cout << "X Axis: " << xAxis << ", Y Axis: " << yAxis << std::endl; 
        }
        // Optional: Render OpenGL scene

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}