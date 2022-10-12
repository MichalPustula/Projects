#pragma once

#include "../include/Field.hpp"


#include <iostream>
#include <vector>

enum class FieldState{Empty, Snake, Food, Wall};


class World
{
public:
    World(int length, int height);

    FieldState getFieldState(const Field field) const;
    void setFieldState(const Field field, FieldState fieldState);

    void printWorld() const;

private:

    std::vector<std::vector<FieldState>> m_fieldStates{};
};