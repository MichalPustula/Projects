#pragma once

#include "../include/Subject.hpp"

// #include <bits/types/cookie_io_functions_t.h>
#include <map>
#include <iostream>

class Server : public Subject 
{
public:
    virtual ~Server(){};
    void attach(std::shared_ptr<Observer> client, int key) override;
    void deattach(int key) override;
    void notify() override;

    ServerState getState() const;
    void setState(ServerState state);
    int getClientsSize() const;

private:
    ServerState currentState = ServerState::NotRunning;
    std::map<int, std::shared_ptr<Observer>> clients;
};