#pragma once
#include"UserStatus.h"
//Базовый класс для всех учётных записей
class User
{
protected:

	unsigned int id;
	std::string login;
	std::string password;
	UserStatus status;

public:

	User();
	User(const std::string& login, const std::string& password);
	User(const User& other);
	virtual ~User();
	virtual void setId(unsigned int id);
	virtual unsigned int getId()const;
	virtual void setLogin(const std::string& login) {};
	virtual void setPassword(const std::string& password) {};
	virtual std::string getPasword()const;
	virtual std::string getLogin()const;
	virtual UserStatus getStatus()const;
	virtual void setStatus(UserStatus status);

	template<class Archive>
	void serialize(Archive& ar, unsigned int version)
	{
		ar& id;
		ar& login;
		ar& password;
		ar& status;
	}

};

