#pragma once

#include "../include/Field.hpp"

#include <list>

enum class Direction {Up, Down , Left, Right};

class Snake
{
public:
    Snake();
    void setDirection(Direction direction);
    Direction getDirection() const;
    Field calculateNextSegment(Direction direction);
    void removeTail();
    void addHead(Field segment);
    Field front();
    Field back();

    std::list<Field> m_segments{};
    Direction m_direction;
};