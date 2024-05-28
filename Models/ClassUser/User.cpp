#include "User.h"

User::User(std::string name, std::string surname, int age, std::string login, std::string password)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->login = login;
	this->password = password;
}
User::User()
{
	this->name = " ";
	this->surname = " ";
	this->age = 0;
	this->login = " ";
	this->password = " ";
}

std::string User::GetName()
{
	return this->name;
}
std::string User::GetSurname()
{
	return this->surname;
}

std::string User::GetLogin()
{
	return this->login;
}
std::string User::GetPassword()
{
	return this->password;
}

void User::operator=(const User& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->login = other.login;
	this->password = other.password;
}

std::ostream& operator<<(std::ostream& out, User& human)
{
	out << "Name: " << human.name << '\n' << "Surname: " << human.surname << '\n' << "Age: " << human.age << '\n';
	return out;
}

//дружественная перегрузка >>
std::istream& operator>>(std::istream& in, User& human)
{
	std::cout << "Enter name: ";
	in >> human.name;

	std::cout << "Enter surname: ";
	in >> human.surname;

	std::string input = "-1";
	do {
		std::cout << "Enter age: ";
		in >> input;
		try
		{
			human.age = std::stoi(input);
		}
		catch (...)
		{
			std::cerr << "Error: Incorrect value\n";
			input.clear();
			human.age = -1;
		}
		
	} while (human.age < 0);

	std::cout << "Enter login: ";
	in >> human.login;

	std::cout << "Enter password: ";
	in >> human.password;

	return in;
}