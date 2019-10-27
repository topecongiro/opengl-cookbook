//
// Created by topec on 2019/10/27.
//

#ifndef OPENGL_COOKBOOK_WINDOW_H
#define OPENGL_COOKBOOK_WINDOW_H

#include <memory>

#include <GLFW/glfw3.h>

class Window {
public:
    explicit Window(size_t height, size_t width);
    static std::unique_ptr<Window> CreateNew(size_t height, size_t width);

    void PollEvents() const;
    bool ShouldClose() const;
    void SwapBuffers() const;

    ~Window();
private:

    size_t height_;
    size_t width_;
    GLFWwindow *window_;
};


#endif //OPENGL_COOKBOOK_WINDOW_H
