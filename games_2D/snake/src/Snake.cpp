#include "../include/Snake.hpp"

Snake::Snake(): m_direction(Direction::Right)
{
    m_segments.emplace_back(Field{4,4});
    m_segments.emplace_back(Field{3,4});
    m_segments.emplace_back(Field{2,4});
    m_segments.emplace_back(Field{1,4});
}

Direction Snake::getDirection() const {return m_direction;}

void Snake::setDirection(Direction direction)
{
    if (direction == Direction::Up && m_direction != Direction::Down) 
    {m_direction = Direction::Up;}

    if (direction == Direction::Down && m_direction != Direction::Up) 
    {m_direction = Direction::Down;}

    if (direction == Direction::Left && m_direction != Direction::Right) 
    {m_direction = Direction::Left;}

    if (direction == Direction::Right && m_direction != Direction::Left) 
    {m_direction = Direction::Right;}
}

Field Snake::calculateNextSegment()
{
    Field nextSegment = m_segments.front();
    
    if (m_direction == Direction::Right)  { nextSegment.x = nextSegment.x + 1; }
    if (m_direction == Direction::Left) { nextSegment.x = nextSegment.x -1; }
    if (m_direction == Direction::Up) { nextSegment.y = nextSegment.y + 1; }
    if (m_direction == Direction::Down) { nextSegment.y = nextSegment.y - 1; }

    return nextSegment;
}

void Snake::removeTail()
{
    m_segments.pop_back();
}

void Snake::addHead(Field segment)
{
    m_segments.emplace_front(segment);
}

Field Snake::front()
{
    return m_segments.front();
}

Field Snake::back()
{
    return m_segments.back();
}


