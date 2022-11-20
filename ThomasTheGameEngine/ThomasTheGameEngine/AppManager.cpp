#include"AppManager.h"


int main()
{
    Game game;

    Graphics::window.createWindow();
    Graphics::setupGraphics();
    Input::initKeys(Graphics::window.window);
    game.setup();
    while (!glfwWindowShouldClose(Graphics::window.window))
    {
        game.loop();
        Input::updateKeys();


        Graphics::clearScreen();
        game.currentScene->render();
        Graphics::graphicsLoop();
    }
    return 0;
}