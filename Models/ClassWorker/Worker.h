#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "..\ClassUser\User.h"
#include "..\ClassVector\myVector.h"

class FactoryWorker : public User {

public:
	FactoryWorker();
	FactoryWorker(std::string name, std::string surname, int age, std::string login, std::string password, std::string jobTitle);
	
	void PrintInfo() override;
	void AddInfo() override;
	void ChangeInfo() override;
	static void SearchInfo(myVector<FactoryWorker>& data);
	int GetAge() override { return this->age; }

	void operator = (FactoryWorker other);
	bool operator>(const FactoryWorker& right);
	bool operator<(const FactoryWorker& right);

	friend  std::ostream& operator << (std::ostream&, FactoryWorker&);
	friend std::istream& operator >>(std::istream& in, FactoryWorker& human);

	std::string GetJobTitle();
	
	void Clear();

	static void ReadWorkersInfoFromTxt(myVector<FactoryWorker> &workers);
	static void UpdateWorkersInfoInTxt(myVector<FactoryWorker> &workers);

private:

	std::string jobTitle;

};
