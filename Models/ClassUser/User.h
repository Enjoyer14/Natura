#pragma once
#include <string>
#include "..\ClassVector\myVector.h"

class User {

public:
	User(std::string name, std::string surname, int age, std::string login, std::string password);
	User();

	virtual void PrintInfo() = 0;
	virtual void AddInfo() = 0;
	virtual void ChangeInfo() = 0;

	std::string GetName();
	std::string GetSurname();
	virtual int GetAge() = 0;
	std::string GetLogin();
	std::string GetPassword();

	void operator= (const User& other);

	friend  std::ostream& operator << (std::ostream&, User&);
	friend std::istream& operator >>(std::istream& in, User& human);

protected:

	std::string name;
	std::string surname;
	int age;
	std::string login;
	std::string password;

};