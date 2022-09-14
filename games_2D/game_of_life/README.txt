to compile and run on linux: (requires gtest, CMake, gcc)

- in GameOfLife folder create build folder
- open terminal in build folder

in terminal type:
$ cmake ..

- $ make run_game
or
- $ make run_tests

to compile and run without CMake, open terminal in game_of_life folder, then type:
$ g++ src/main.cpp src/Game.cpp src/Grid.cpp
$ ./a.out

project info:
purpose of this project is to write implementation of 2D game of life

- origin of the grid is in left up corner

to do:

- write methods to place and rotate shapes with wall checking

- refactor tests after they are no longer usefull - keeping old tests as history of tdd.

- consider if std::vector<bool> and at() method are optimal choices for data storing and acces.

- write countNeighboursOfCell(bool state, int x, int y) method - done

-  find how to handle methods like clearGrid(), additional set functions, which are usefull for testing but should be hidden from user -
release and test versions?, functions that sets neighbours should be first getters for single neighbours and then replaced by countNeighboursOfCell().

find solution to problem with polimorphism
- there is needed the same implementation of method that in one use case 
takes (int index) in second (int x, int y), the implementation of method is pretty much the same - method(int index) caluclates x, y and calls method(int x, int y);
