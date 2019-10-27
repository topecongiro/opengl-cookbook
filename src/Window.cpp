//
// Created by topec on 2019/10/27.
//

#include "Window.h"

Window::Window(size_t height, size_t width) : height_(height), width_(width), window_(nullptr) {}

std::unique_ptr<Window> Window::CreateNew(size_t height, size_t width) {
    if (!glfwInit()) {
        return nullptr;
    }

    auto window = std::make_unique<Window>(height, width);
    window->window_ = glfwCreateWindow(640, 480, "Example", nullptr, nullptr);
    if (window->window_ == nullptr) {
        return nullptr;
    }

    glfwMakeContextCurrent(window->window_);

    return window;
}

Window::~Window() {
    if (window_ != nullptr) {
        glfwTerminate();
        window_ = nullptr;
    }
}

bool Window::ShouldClose() const {
    return glfwWindowShouldClose(window_);
}

void Window::SwapBuffers() const {
    glfwSwapBuffers(window_);
}

void Window::PollEvents() const {
    glfwPollEvents();
}
