#include"AppManager.h"

Game game;

int main()
{

    Graphics::window.createWindow();
    Graphics::setupGraphics();
    Input::initKeys(Graphics::window.window);
    game.setup();
    while (!glfwWindowShouldClose(Graphics::window.window))
    {
        game.loop();
        game.sceneloop();
        Input::updateKeys();


        Graphics::graphicsLoop();
        Graphics::clearScreen();
    }
    game.end();
    return 0;
}