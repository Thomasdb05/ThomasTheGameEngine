#include"Graphics.h"

int main()
{
    Graphics::window.createWindow();
    Graphics::setupGraphics();
    Graphics::graphicsLoop();
    return 0;
}