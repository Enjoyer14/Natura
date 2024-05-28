#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "..\ClassUser\User.h"
#include "..\ClassVector\myVector.h"
#include "..\ClassProduct\Product.h"


class Provider : public User {

public:
	Provider();
	Provider(std::string name, std::string surname, int age, std::string login, std::string password, std::string productType);

	void PrintInfo() override;
	void AddInfo() override;
	void ChangeInfo() override;
	static void SearchInfo(myVector<Provider>& data);

	int GetAge() override { return this->age; }

	void operator = (Provider other);
	bool operator>(const Provider& right);
	bool operator<(const Provider& right);

	friend  std::ostream& operator << (std::ostream&, Provider&);
	friend std::istream& operator >>(std::istream& in, Provider& human);

	std::string GetProductType();

	void Clear();

	static void ReadProvidersInfoFromTxt(myVector<Provider>& human);
	static void UpdateProvidersInfoInTxt(myVector<Provider>& human);

private:

	Product product;
	std::string productType;
};

