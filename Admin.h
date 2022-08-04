#pragma once
#include "pch.h"
#include "User.h"
using namespace std;
class Admin :
    public User
{
protected:
    // Унаследовано через User
    virtual void setLogin(const std::string& login) override;
    virtual void setPassword(const std::string& login) override;
public:

    Admin();
    Admin(string login, string password);
	template<class Archive>
	void serialize(Archive& ar, unsigned int version)
	{
        User::serialize(ar, version);
	}
};

