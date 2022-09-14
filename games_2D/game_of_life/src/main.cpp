#include "../include/Game.hpp"
#include "../include/Grid.hpp"



int main()
{
    Game game(10,15);
    game.placeGlider(1,1);
    game.play();
}