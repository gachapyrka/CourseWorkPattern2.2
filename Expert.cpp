#include "pch.h"
#include "Expert.h"

void Expert::setLogin(const std::string& login)
{
}

void Expert::setPassword(const std::string& login)
{
}

Expert::Expert() : User()
{
}

Expert::Expert(string login, string password)
	: User(login, password)
{
}
