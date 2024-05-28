#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "..\ClassVector\myVector.h"

class Product {

public:

	Product(std::string productType, std::string productTitle, double cost, int quantity);
	Product();

	void PrintInfo();
	void AddInfo();
	void ChangeInfo();
	static void SearchInfo(myVector<Product> &data);

	bool operator>(const Product& right);
	bool operator<(const Product& right);

	friend  std::ostream& operator << (std::ostream&, Product&);
	friend std::istream& operator >>(std::istream& in, Product& human);

	std::string GetType();
	std::string GetTitle();
	double GetCost();
	int GetQuantity();

	void SetCost(double cost);
	void SetQuantity(int quantity);

;
	void Clear();

	static void ReadProductsInfoFromTxt(myVector<Product>& products);
	static void UpdateProductsInfoInTxt(myVector<Product>& products);

private:

	std::string productType;
	std::string productTitle;
	double cost;
	int quantity;

};