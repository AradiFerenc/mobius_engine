#include "log.h"
#include "window.h"

int main() {
    mobius::Window window("asd", 800, 600);

    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
    while (!window.ShouldClose()) {
        window.Clear();

        glBegin(GL_TRIANGLES);
        glVertex2f(-.5f, -.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -.5f);
        glEnd();

        window.Update();
    }
    return 0;
}
