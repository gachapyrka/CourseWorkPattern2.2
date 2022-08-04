#include "pch.h"
#include "Admin.h"

void Admin::setLogin(const std::string& login)
{
}

void Admin::setPassword(const std::string& login)
{
}

Admin::Admin() : User()
{
}

Admin::Admin(string login, string password)
	: User(login, password)
{
}