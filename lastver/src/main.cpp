// main.cpp
// By Monsieur_JaKy for hypermario project

#include "Game.h"

int main(void)
{
    Game game;

    game.UseVerticalSync(true);

    while (game.IsOpened())
    {
        game.checkEvent();

        game.evolue();

        game.Clear();

        game.drawAll();

        game.Display();
    }

    return EXIT_SUCCESS;
}
