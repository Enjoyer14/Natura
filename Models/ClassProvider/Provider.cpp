#include "Provider.h"



Provider::Provider(std::string name, std::string surname, int age, std::string login, std::string password, std::string productType) : User(name, surname, age, login, password)
{
	this->productType = productType;
}
Provider::Provider() : User()
{
	this->name = " ";

}

void Provider::operator=(Provider other)
{
	User::operator=(other);
	this->productType = other.productType;
}

bool Provider::operator>(const Provider& right)
{
	return this->age > right.age;
}
bool Provider::operator<(const Provider& right)
{
	return this->age < right.age;
}

void Provider::PrintInfo()
{
	std::cout << *this;
}
void Provider::AddInfo()
{
	std::cin >> *this;
}

void Provider::ChangeInfo()
{
	std::cin >> *this;
}

void Provider::SearchInfo(myVector<Provider>& data)
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

std::string Provider::GetProductType()
{
	return this->productType;
}

void Provider::Clear()
{
	this->name.clear();
	this->surname.clear();
	this->age = 0;
	this->login.clear();
	this->password.clear();
	this->productType.clear();
}

void Provider::ReadProvidersInfoFromTxt(myVector<Provider>& human)
{
	int i{};
	std::ifstream fin("Providers.txt");
	Provider buff;
	while (fin >> buff.name >> buff.surname >> buff.age >> buff.login >> buff.password >> buff.productType) {
		human.pushBack(buff);
		buff.Clear();
	}
	fin.close();
}
void Provider::UpdateProvidersInfoInTxt(myVector<Provider>& human)
{
	std::ofstream fout("Providers.txt");
	for (auto x : human){
		fout << x.GetName() << '\t' << x.GetSurname() << '\t' << x.GetAge() << '\t' << x.GetLogin() << '\t' << x.GetPassword() << '\t' << x.GetProductType() << std::endl;
	}
	fout.close();
}

