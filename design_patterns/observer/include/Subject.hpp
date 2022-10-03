#pragma once

#include "../include/Observer.hpp"

#include <memory>

class Subject 
{
public:
    virtual ~Subject(){};
    virtual void attach(std::shared_ptr<Observer> client, int key) = 0;
    virtual void deattach(int key) = 0;
    virtual void notify() = 0;
};