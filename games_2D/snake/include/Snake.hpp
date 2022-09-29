#pragma once

#include <list>

struct Segment
{
    int x;
    int y;
};

class Snake
{
public:
    Snake();


private:

    std::list<Segment> m_segments{};
};