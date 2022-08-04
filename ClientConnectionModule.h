#pragma once
#include"ClientProtocol.h"
#include"Client.h"
#include"Admin.h"
#include"Expert.h"
class ClientConnectionModule
{
protected:

	ClientProtocol protocol;

public:

	ClientConnectionModule();

	ClientConnectionModule(const string& serverIP, unsigned int serverPort);

	TypeOfUser authorization(const string& login, const string& password);

	AnswerFromServer registration(TypeOfUser type, const string& login, const string& password);

	AnswerFromServer rate(CommandToServer command, double rate);

	Client findClientByLogin(string login);

	Expert findExpertByLogin(string login);

	Admin findAdminByLogin(string login);

	AnswerFromServer registerNewAdmin(string login, string password);

	AnswerFromServer registerNewClient(string login, string password);

	AnswerFromServer registerNewExpert(string login, string password, double rateWeight);

	AnswerFromServer banClientWith(string login);

	AnswerFromServer banExpertWith(string login);

	AnswerFromServer unbanClientWith(string login);

	AnswerFromServer unbanExpertWith(string login);

	AnswerFromServer deleteClientWith(string login);

	AnswerFromServer deleteExpertWith(string login);

	void closeConnection();

};

