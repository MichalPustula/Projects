#include "../include/World.hpp"


World::World(int length, int height): 
m_fieldStates(height, std::vector<FieldState>(length, FieldState::Empty))
{
}

FieldState World::getFieldState(const Field field) const
{
    return m_fieldStates.at(field.y).at(field.x);
}

void World::setFieldState(const Field field, FieldState fieldState) 
{
    m_fieldStates.at(field.y).at(field.x) = fieldState;
}

void World::printWorld() const
{
    for (size_t i = 0; i < m_fieldStates.size(); i++)
    {
        for (size_t j = 0; j < m_fieldStates.at(0).size();j++)
        {
            if (m_fieldStates.at(i).at(j) == FieldState::Empty)
            {
                std::cout << " . ";
                continue;
            }

            if (m_fieldStates.at(i).at(j) == FieldState::Wall)
            {
                std::cout << " # ";
                continue;
            }

            if (m_fieldStates.at(i).at(j) == FieldState::Snake)
            {
                std::cout << " o ";
                continue;
            }

            if (m_fieldStates.at(i).at(j) == FieldState::Food)
            {
                std::cout << " x ";
                continue;
            }
        }
        std::cout << '\n';
    }
}

