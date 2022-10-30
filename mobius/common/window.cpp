#include "window.h"
#include "log.h"

namespace mobius
{

void ResizeCallback(GLFWwindow *window, int width, int height)
{
    //TODO: make this resize the Window objects width and height
    glViewport(0, 0, width, height);
}

Window::Window(const std::string& title, const size_t width, const size_t height)
{
    this->title_ = title;
    this->width_ = width;
    this->height_ = height;
    if (!glfwInit()) {
        LOGE("Failed to initialize GLFW!");
        return;
    }

    handle_ = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!handle_) {
        glfwTerminate();
        LOGE("Failed to create window!");
        return;
    }

    glfwMakeContextCurrent(handle_);
    glfwSetWindowSizeCallback(handle_, ResizeCallback);

    LOGI("%s", glGetString(GL_VERSION));
}

Window::~Window()
{
    glfwTerminate();
}

void Window::Update()
{
    glfwPollEvents();
    glfwSwapBuffers(handle_);
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(handle_);
}

void Window::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

}