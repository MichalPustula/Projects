to compile and run tests on linux: (requires gtest, CMake, gcc)

- in GameOfLife folder create build folder
- open terminal in build folder

in terminal type:
cmake ..
make
./game_of_life_tests

project info:
purpose of this project is to write implementation of 2D game of life

- origin of the grid is in left up corner

to do:

- refactor tests after they are no longer usefull - keeping old tests as history of tdd.

- consider if std::vector<bool> and at() method are optimal choices for data storing and acces.

- write countNeighboursOfCell(bool state, int x, int y) method - done

-  find how to handle methods like clearGrid(), additional set functions, which are usefull for testing but should be hidden from user - release and debuggin versions?

find solution to problem with polimorphism
- there is needed the same implementation of method that in one use case 
takes (int index) in second (int x, int y), the implementation of method is pretty much the same - method(int index) caluclates x, y and calls method(int x, int y);
