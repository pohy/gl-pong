#include <iostream>

#define GLEW_STATIC
#include "include/GLEW/glew.h"
#include "include/GLFW/glfw3.h"

void onKey(GLFWwindow * p_window, int key, int scancode, int action, int mode);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow * p_window = glfwCreateWindow(854, 480, "OGL", nullptr, nullptr);
    if (p_window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(p_window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    int width, height;
    glfwGetFramebufferSize(p_window, &width, &height);
    glViewport(0, 0, width, height);

    glfwSetKeyCallback(p_window, onKey);

    while (!glfwWindowShouldClose(p_window)) {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(p_window);
    }

    glfwTerminate();
    return 0;
}

void onKey(GLFWwindow * p_window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(p_window, GL_TRUE);
    }
}