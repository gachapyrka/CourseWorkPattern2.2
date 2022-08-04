#pragma once
#include "pch.h"
#include "ClientConnectionModule.h"

ClientConnectionModule::ClientConnectionModule()
    : protocol("127.0.0.1", 15000)
{
    protocol.establishConection();
}

ClientConnectionModule::ClientConnectionModule(const string& serverIP, unsigned int serverPort)
    : protocol(serverIP, serverPort)
{
    protocol.establishConection();
}

TypeOfUser ClientConnectionModule::authorization(const string& login, const string& password)
{
    protocol.sendCommand(CommandToServer::AUTHORIZATION);
    protocol.sendLogin(login);
    protocol.sendPassword(password);
    return protocol.receiveTypeOfUser();
}

AnswerFromServer ClientConnectionModule::registration(TypeOfUser type, const string& login, const string& password)
{
    protocol.sendCommand(CommandToServer::REGISTRATION);
    protocol.sendTypeOfUser(type);
    protocol.sendLogin(login);
    protocol.sendPassword(password);
    return protocol.receiveAnswer();

}

AnswerFromServer ClientConnectionModule::rate(CommandToServer command, double rate)
{
    protocol.sendCommand(command);
    protocol.sendString(to_string(rate));
    return protocol.receiveAnswer();
}

Client ClientConnectionModule::findClientByLogin(string login)
{
    protocol.sendCommand(CommandToServer::FIND_CLIENT_BY_LOGIN);
    protocol.sendLogin(login);
    return protocol.receiveObject<Client>();
}

Expert ClientConnectionModule::findExpertByLogin(string login)
{
    protocol.sendCommand(CommandToServer::FIND_EXPERT_BY_LOGIN);
    protocol.sendLogin(login);
    return protocol.receiveObject<Expert>();
}

Admin ClientConnectionModule::findAdminByLogin(string login)
{
    protocol.sendCommand(CommandToServer::FIND_ADMIN_BY_LOGIN);
    protocol.sendLogin(login);
    return protocol.receiveObject<Admin>();
}

AnswerFromServer ClientConnectionModule::registerNewAdmin(string login, string password)
{
    protocol.sendCommand(CommandToServer::REDISTER_NEW_USER);
    protocol.sendTypeOfUser(TypeOfUser::ADMIN);
    protocol.sendLogin(login);
    protocol.sendPassword(password);
    return protocol.receiveAnswer();
}

AnswerFromServer ClientConnectionModule::registerNewClient(string login, string password)
{
    protocol.sendCommand(CommandToServer::REDISTER_NEW_USER);
    protocol.sendTypeOfUser(TypeOfUser::CLIENT);
    protocol.sendLogin(login);
    protocol.sendPassword(password);
    return protocol.receiveAnswer();
}

AnswerFromServer ClientConnectionModule::registerNewExpert(string login, string password, double expertRate)
{
    protocol.sendCommand(CommandToServer::REDISTER_NEW_USER);
    protocol.sendTypeOfUser(TypeOfUser::EXPERT);
    protocol.sendLogin(login);
    protocol.sendPassword(password);
    protocol.sendString(to_string(expertRate));
    return protocol.receiveAnswer();
}

AnswerFromServer ClientConnectionModule::banClientWith(string login)
{
    protocol.sendCommand(CommandToServer::BAN_CLIENT);
    protocol.sendLogin(login);
    return protocol.receiveAnswer();
}

AnswerFromServer ClientConnectionModule::banExpertWith(string login)
{
    protocol.sendCommand(CommandToServer::BAN_EXPERT);
    protocol.sendLogin(login);
    return protocol.receiveAnswer();
}

AnswerFromServer ClientConnectionModule::unbanClientWith(string login)
{
    protocol.sendCommand(CommandToServer::UNBAN_CLIENT);
    protocol.sendLogin(login);
    return protocol.receiveAnswer();
}

AnswerFromServer ClientConnectionModule::unbanExpertWith(string login)
{
    protocol.sendCommand(CommandToServer::UNBAN_EXPERT);
    protocol.sendLogin(login);
    return protocol.receiveAnswer();
}

AnswerFromServer ClientConnectionModule::deleteClientWith(string login)
{
    protocol.sendCommand(CommandToServer::DELETE_CLIENT);
    protocol.sendLogin(login);
    return protocol.receiveAnswer();
}

AnswerFromServer ClientConnectionModule::deleteExpertWith(string login)
{
    protocol.sendCommand(CommandToServer::DELETE_EXPERT);
    protocol.sendLogin(login);
    return protocol.receiveAnswer();
}

void ClientConnectionModule::closeConnection()
{
    protocol.sendCommand(CommandToServer::DISCONNECT);
    protocol.closeConnection();
}

#include "pch.h"