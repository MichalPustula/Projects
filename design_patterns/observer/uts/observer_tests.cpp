#include "gtest/gtest.h"
#include "../include/Client.hpp"
#include "../include/Server.hpp"



TEST(observerTests, NotifyFunctionalityOfServer)
{
    Server server;
    std::shared_ptr<Observer> client1 = std::make_shared<Client>();

    server.attach(client1, 872);
    server.setState(ServerState::Running);
    server.notify();

    EXPECT_EQ(client1->getLastServerState(), ServerState::Running);
};

TEST(observerTests, UpdateFunctionalityOfClient)
{
    Server server;
    std::shared_ptr<Observer> client1 = std::make_shared<Client>();

    server.attach(client1, 872);
    server.setState(ServerState::Running);
    client1->update(server.getState());

    EXPECT_EQ(client1->getLastServerState(), ServerState::Running);

};

TEST(observerTests, CannotDeattachSameIDTwice) 
{
    Server server;
    std::shared_ptr<Observer> client1 = std::make_shared<Client>();  

    server.attach(client1, 872);
    server.deattach(872);
    server.deattach(872);

    EXPECT_EQ(server.getClientsSize(), 0);
};


TEST(observerTests, ClientCanBeDeattached) 
{
    Server server;
    std::shared_ptr<Observer> client1 = std::make_shared<Client>();

    server.attach(client1, 872);
    server.deattach(872);

    EXPECT_EQ(server.getClientsSize(), 0);
};

TEST(observerTests, ClientWithSameIdCantBeAttached) 
{
    Server server;
    std::shared_ptr<Observer> client1 = std::make_shared<Client>();

    server.attach(client1, 872);
    server.attach(client1, 872);

    EXPECT_EQ(server.getClientsSize(), 1);
};

TEST(observerTests, ClientIsAttachedToServer) 
{
    Server server;
    std::shared_ptr<Observer> client1 = std::make_shared<Client>();

    server.attach(client1, 872);

    EXPECT_EQ(server.getClientsSize(), 1);
};

TEST(observerTests, clientCreated) 
{
    Client client;
    EXPECT_EQ(client.getLastServerState(), ServerState::NotRunning);
};

TEST(observerTests, callServerSetStateSetsState) 
{
    Server server;

    server.setState(ServerState::Running);

    EXPECT_EQ(server.getState(), ServerState::Running);
};

TEST(observerTests, callServerGetStateReturnNotRunning) 
{
    Server server;
    EXPECT_EQ(server.getState(), ServerState::NotRunning);
};

TEST(observerTests, creatingServer) 
{
    Server server;
    EXPECT_EQ(server.getState(), ServerState::NotRunning);
}