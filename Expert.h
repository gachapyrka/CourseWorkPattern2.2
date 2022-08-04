#pragma once
#include "User.h"
using namespace std;
class Expert :
    public User
{
protected:



public:

    // Унаследовано через User
    virtual void setLogin(const std::string& login) override;
    virtual void setPassword(const std::string& login) override;

    Expert();
    Expert(string login, string password);

	template<class Archive>
	void serialize(Archive& ar, unsigned int version)
	{
        User::serialize(ar, version);
	}

};

