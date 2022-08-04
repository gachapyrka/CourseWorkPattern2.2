#include "pch.h"
#include "User.h"

std::string User::getPasword() const
{
    return password;
}

std::string User::getLogin() const
{
    return password;
}

UserStatus User::getStatus() const
{
	return status;
}

void User::setStatus(UserStatus status)
{
	this->status = status;
}

User::User()
{
	id = 0;
	login = "empty";
	password = "empty";
	status = UserStatus::NOT_BANNED;
}

User::User(const std::string& login, const std::string& password) : User()
{
	setLogin(login);
	setPassword(password);
}

User::User(const User& other)
{
	id = other.id;
	login = other.login;
	password = other.password;
}

User::~User()
{
}

void User::setId(unsigned int id)
{
	if (id > 0)
	{
		this->id = id;
	}
}

unsigned int User::getId() const
{
	return id;
}
