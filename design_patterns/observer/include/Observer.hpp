#pragma once


enum class ServerState { NotRunning, Initializing, Running };

class Observer 
{
public:
    virtual ~Observer(){};
    virtual void update(ServerState serverstate) = 0;
    virtual ServerState getLastServerState() const = 0;
};







