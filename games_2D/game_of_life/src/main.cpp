#include "../include/Game.hpp"
#include "../include/Grid.hpp"


int main()
{
    Game game(15,20);
    game.placeGlider(2,16);
    game.placeSpaceShip(2,2);
    game.placeSpaceShip(3,8);

    game.play();
}