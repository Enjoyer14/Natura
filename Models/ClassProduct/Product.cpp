#include "Product.h"

Product::Product(std::string productType, std::string productTitle, double cost, int quantity)
{
	this->productType = productType;
	this->productTitle = productTitle;
	this->cost = cost;
	this->quantity = quantity;
}
Product::Product() {
	this->productType = "";
	this->productTitle = "";
	this->cost = 0;
	this->quantity = 0;
}

void Product::PrintInfo() {
	std::cout << *this;
}

std::string Product::GetType()
{
	return this->productType;
}
std::string Product::GetTitle()
{
	return this->productTitle;
}
double Product::GetCost() { return this->cost; }
int Product::GetQuantity() { return this->quantity; }

void Product::SetCost(double cost)
{
	this->cost = cost;
}
void Product::SetQuantity(int quantity)
{
	this->quantity = quantity;
}

void Product::AddInfo()
{
	std::cin >> *this;

}

void Product::ChangeInfo()
{
	std::cin >> *this;
}

void Product::SearchInfo(myVector<Product> &data)
{
	std::cout << "Enter product type for search: ";
	std::string type{};
	std::getline(std::cin, type);
	std::cin.ignore(32767, '\n');

	for (auto x : data)
	{
		if (x.productType == type)
		{
			x.PrintInfo();
		}
	}
}

void Product::Clear()
{
	this->productType.clear();
	this->productTitle.clear();
	this->cost = 0;
	this->quantity = 0;
}

void Product::ReadProductsInfoFromTxt(myVector<Product>& products)
{
	int i{};
	std::ifstream fin("Products.txt");
	Product buff;
	while (fin >> buff.productType >> buff.productTitle >> buff.cost >> buff.quantity) {
		products.pushBack(buff);
		buff.Clear();
	}
	fin.close();
}
void Product::UpdateProductsInfoInTxt(myVector<Product>& products)
{
	std::ofstream fout("Products.txt");
	for (auto x : products)
	{
		fout << x.GetType() << '\t' << x.GetTitle() << '\t' << x.GetCost() << '\t' << x.GetQuantity() << std::endl;
	}
	fout.close();
}

bool Product::operator>(const Product& right)
{
	return (this->cost > right.cost);
}
bool Product::operator<(const Product& right)
{
	return (this->cost < right.cost);
}

std::ostream& operator<<(std::ostream& out, Product& product)
{
	std::cout << "Product type: " << product.productType << '\n' << "Product title: " << product.productTitle << '\n' << "Cost: " << product.cost << '\n' << "Quantity: " << product.quantity << std::endl << std::endl;
	return out;
}

//дружественная перегрузка >>
std::istream& operator>>(std::istream& in, Product& product)
{
	std::cout << "Enter type: ";
	in >> product.productType;
	std::cin.ignore(32767, '\n');

	std::cout << "Enter product title: ";
	in >> product.productTitle;
	std::cin.ignore(32767, '\n');

	std::string input = "-1";
	do {
		std::cout << "Enter cost: ";
		in >> input;

		try {
			product.cost = std::stoi(input);
		}
		catch (...) {
			std::cerr << "Error: Incorrect argument!" << std::endl;
			input.clear();
			product.cost = -1;
		}

	} while (product.cost < 0);

	input = "-1";
	do {
		std::cout << "Enter quantity: ";
		in >> input;

		try {
			product.quantity = std::stoi(input);
		}
		catch (...) {
			std::cerr << "Error: Incorrect argument!" << std::endl;
			input.clear();
			product.quantity = -1;
		}

	} while (product.quantity < 0);

	return in;
}