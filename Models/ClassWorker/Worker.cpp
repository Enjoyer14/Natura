#include "Worker.h"

FactoryWorker::FactoryWorker(std::string name, std::string surname, int age, std::string login, std::string password, std::string jobTitle) : User(name, surname, age, login, password)
{
	this->jobTitle = jobTitle;
}
FactoryWorker::FactoryWorker() : User()
{
	this->jobTitle = " ";
}

void FactoryWorker::operator=(FactoryWorker other)
{
	User::operator=(other);
	this->jobTitle = other.jobTitle;
}
bool FactoryWorker::operator>(const FactoryWorker& right)
{
	return this->age > right.age;
}
bool FactoryWorker::operator<(const FactoryWorker& right)
{
	return this->age < right.age;
}

//��� ���������� <<
void FactoryWorker::PrintInfo()
{
	std::cout << *this;
}

void FactoryWorker::AddInfo()
{
	std::cin >> *this;

}

void FactoryWorker::ChangeInfo()
{
	std::cin >> *this;
}

void FactoryWorker::SearchInfo(myVector<FactoryWorker>& data)
{
	std::string input = "-1";
	int age = -1;
	do {
		std::cout << "Enter age for search: ";
		std::cin >> input;
		try
		{
			age = std::stoi(input);
		}
		catch (...) {
			std::cerr << "Error: Incorrect age!" << std::endl;
			input.clear();
			age = -1;
		}
	} while (age < 0);

	for (auto x : data)
	{
		if (x.age == age)
		{
			x.PrintInfo();
		}
	}
}

std::string FactoryWorker::GetJobTitle()
{
	return this->jobTitle;
}

void FactoryWorker::Clear()
{
	this->name.clear();
	this->surname.clear();
	this->age = 0;
	this->login.clear();
	this->password.clear();
	this->jobTitle.clear();
}

void FactoryWorker::ReadWorkersInfoFromTxt(myVector<FactoryWorker> &workers)
{
	int i{};
	std::ifstream fin("Workers.txt");
	FactoryWorker buff;
	while (fin >> buff.name >> buff.surname >> buff.age >> buff.login >> buff.password >> buff.jobTitle) {
		workers.pushBack(buff);
		buff.Clear();
	}
	fin.close();
}
void FactoryWorker::UpdateWorkersInfoInTxt(myVector<FactoryWorker> &workers)
{
	std::ofstream fout("Workers.txt");
	for (auto x : workers)
	{
		fout << x.GetName() << '\t' << x.GetSurname() << '\t' << x.GetAge() << '\t' << x.GetLogin() << '\t' << x.GetPassword() << '\t' << x.GetJobTitle() << std::endl;
	}
	fout.close();
}


