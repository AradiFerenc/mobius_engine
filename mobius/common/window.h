#ifndef MOBIUS_WINDOW_H
#define MOBIUS_WINDOW_H

#include <string>

#include "GLFW/glfw3.h"

namespace mobius {

class Window {
    uint32_t width_;
    uint32_t height_;
    std::string title_;
    GLFWwindow *handle_;

public:
    Window(const std::string &title, const size_t width, const size_t height);
    ~Window();

    void Update();
    void Clear() const;
    bool ShouldClose() const;


    inline uint32_t Width() const { return width_; }
    inline uint32_t Height() const { return height_; }
    inline const std::string &Title() const { return title_; }

};

}

#endif //MOBIUS_WINDOW_H
