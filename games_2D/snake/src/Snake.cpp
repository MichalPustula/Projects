#include "../include/Snake.hpp"



Snake::Snake()
{
    m_segments.emplace_back(Segment{4,5});
    m_segments.emplace_back(Segment{4,4});
    m_segments.emplace_back(Segment{4,3});
    m_segments.emplace_back(Segment{4,2});
}