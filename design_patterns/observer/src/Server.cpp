#include "../include/Server.hpp"


void Server::attach(std::shared_ptr<Observer> client, int key)
{
    auto search = clients.find(key);
    if (search != clients.end()) 
    {
        std::cout << "Client is already attached" << std::endl;
    } 
    else 
    {
        clients[key] = client;
    }
}

void Server::deattach(int key)
{
    if (clients.find(key) == clients.end()) { return; }
    clients.erase(key);
    std::cout << "Client with " << key << " is deattached" << std::endl;
};

void Server::notify() 
{
    for(auto i: clients)
    {
        i.second->update(currentState);
    }
};

ServerState Server::getState() const { return currentState; }

int Server::getClientsSize() const { return clients.size(); }

void Server::setState(ServerState state) { currentState = state; };
