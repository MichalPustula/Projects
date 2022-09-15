#include "../include/Game.hpp"
#include "../include/Grid.hpp"


int main()
{
    Game game(20,25);
    game.placeGlider(3,8);
    game.placeGlider(7,14);
    game.placeSpaceShip(16,21);


    game.play();
}