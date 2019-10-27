//
// Created by topecongiro on 2019/10/27.
//

#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"

int main()
{
    if (!glfwInit()) {
        std::cerr << "failed to initialize GLFW" << std::endl;
        return 1;
    }

    auto window = Window::CreateNew(640, 480);
    if (window == nullptr) {
        std::cerr << "failed to create a GLFW window" << std::endl;
        return 1;
    }

    if (!gladLoadGL()) {
        std::cerr << "Unable to load OpenGL functions" << std::endl;
        return 1;
    }

    while (!window->ShouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);
        window->SwapBuffers();
        window->PollEvents();
    }

    return 0;
}
