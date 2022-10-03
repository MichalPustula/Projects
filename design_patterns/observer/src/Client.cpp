#include "../include/Client.hpp"


Client::~Client() {}

void Client::update(ServerState serverstate) { lastServerState = serverstate; }

ServerState Client::getLastServerState() const { return lastServerState; }