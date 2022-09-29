#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

enum class FieldState{Empty, Snake, Food};

enum class GameState{Running, Stopped, Defeat, Victory};

struct Field
{
    int x;
    int y;
};

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