to compile and run on linux:

- in GameOfLife folder create build folder
- open terminal in build folder

in terminal type:
cmake ..
make
./game_of_life_tests

project:
purpose of this project is to write implementation of 2D game of life

- origin of the grid is in left up corner

to do:

- consider if std::vector<bool> and at() method are optimal choices for data storing and acces.

- write countNeighboursOfCell(bool state, int x, int y) method - in progress

- how to handle methods like clearGrid(), additional set functions, which are usefull for testing but should be hidden from user.

find solution to problem with polimorphism
- there is needed the same implementation of method that in one use case 
takes (int index) in second (int x, int y), the implementation of method is pretty much the same
