#pragma once

#include "../include/Observer.hpp"



class Client : public Observer 
{
public:
    ~Client() override;

    void update(ServerState serverstate) override;
    ServerState getLastServerState() const override;

private:
    ServerState lastServerState = ServerState::NotRunning;
};