#include "Models/ClassMenu/CMenu.h"
#include "Models/ClassMenuItem/CMenuItem.h"
#include "Models/ClassProduct/Product.h"
#include "Models/ClassWorker/Worker.h"
#include "Models/ClassProvider/Provider.h"
#include "Models/ClassVector/myVector.h"
#include <functional>
#include <fstream>

using namespace std;

const int ITEM_NUMBER = 3;
const int ITEM_NUMBER_2 = 6;

//дружественная перегрузка <<
std::ostream& operator<<(std::ostream& out, FactoryWorker& human)
{
    operator<<(out, (User&)human);
    out << "Job title: " << human.jobTitle << std::endl << std::endl;
    return out;
}

//дружественная перегрузка >>
std::istream& operator>>(std::istream& in, FactoryWorker& human)
{
    operator>>(in, (User&)human);

    std::cout << "Enter job title: ";
    in >> human.jobTitle;
    return in;
}

std::ostream& operator<<(std::ostream& out, Provider& human)
{
    operator<<(out, (User&)human);
    out << "Product type: " << human.productType << std::endl << std::endl;
    return out;
}
//// g++ ./main.cpp ./Models/ClassMenuItem/CMenuItem.cpp ./Models/ClassMenu/CMenu.cpp ./Models/ClassUser/User.cpp ./Models/ClassWorker/Worker.cpp ./Models/ClassProvider/Provider.cpp ./Models/ClassProduct/Product.cpp

//дружественная перегрузка >>
std::istream& operator>>(std::istream& in, Provider& human)
{
    operator>>(in, (User&)human);
    std::cout << "Enter product type: ";
    in >> human.productType;

    return in;
}

int LogIn()
{
    bool isLogIn{};
    std::string login, password;
    while (isLogIn == false) {

        std::cout << "Enter login: ";
        std::cin >> login;
        std::cout << "Enter password: ";
        std::cin >> password;

        ifstream fin("Logs.txt");
        std::string buffLogin, buffPassword;
        if (fin.is_open())
        {
            while (fin >> buffLogin >> buffPassword)
            {
                if (login == buffLogin && password == buffPassword)
                {
                    isLogIn = true;
                    fin.close();
                    std::cout << "Succesfully. " << std::endl;

                    return 1;
                }
            }
            std::cout << "Wrong login or password, try again." << std::endl;
        }
    }
}

int Factory()
{
    myVector<FactoryWorker> workers;

    std::function<int()> funcPrint = std::bind(&myVector<FactoryWorker>::PrintAll, &workers);
    std::function<int()> funcAdd = std::bind(&myVector<FactoryWorker>::AddData, &workers);
    std::function<int()> funcDelete= std::bind(&myVector<FactoryWorker>::DeleteData, &workers);
    std::function<int()> funcSort = std::bind(&myVector<FactoryWorker>::SortByName, &workers);
    std::function<int()> funcChange = std::bind(&myVector<FactoryWorker>::ChangeData, &workers);
    std::function<int()> funcSearch = std::bind(&myVector<FactoryWorker>::SearchData, &workers);

    FactoryWorker::ReadWorkersInfoFromTxt(workers);

    CMenuItem items[ITEM_NUMBER_2]{
        CMenuItem{"Print worker info", funcPrint},
        CMenuItem{"Add worker info.", funcAdd},
        CMenuItem{"Delete worker info.", funcDelete},
        CMenuItem{"Sort human info by surname.", funcSort},
        CMenuItem{"Change human info.", funcChange},
        CMenuItem{"Search info by age.", funcSearch}
    };
    CMenu menu("Factory Menu", items, ITEM_NUMBER_2);
    while(menu.runCommand2()){
        
    };

    FactoryWorker::UpdateWorkersInfoInTxt(workers);

    return 1;
}

int Provide()
{

    Provider him;

    myVector<Provider> workers{};

    std::function<int()> funcPrint = std::bind(&myVector<Provider>::PrintAll, &workers);
    std::function<int()> funcAdd = std::bind(&myVector<Provider>::AddData, &workers);
    std::function<int()> funcDelete = std::bind(&myVector<Provider>::DeleteData, &workers);
    std::function<int()> funcSort = std::bind(&myVector<Provider>::SortByName, &workers);
    std::function<int()> funcChange = std::bind(&myVector<Provider>::ChangeData, &workers);
    std::function<int()> funcSearch = std::bind(&myVector<Provider>::SearchData, &workers);

    Provider::ReadProvidersInfoFromTxt(workers);

    CMenuItem items[ITEM_NUMBER_2]{
        CMenuItem{"Print provider info", funcPrint},
        CMenuItem{"Add provider info.", funcAdd},
        CMenuItem{"Delete provider info.", funcDelete},
        CMenuItem{"Sort human info by surname.", funcSort}, 
        CMenuItem{"Change human info.", funcChange},
        CMenuItem{"Search info by age.", funcSearch}
    };
    CMenu menu("Provider Menu", items, ITEM_NUMBER_2);
    while (menu.runCommand2()) 
    {
        
    };

    Provider::UpdateProvidersInfoInTxt(workers);

    return 2;
}

// g++ ./main.cpp ./Models/ClassMenuItem/CMenuItem.cpp ./Models/ClassMenu/CMenu.cpp ./Models/ClassUser/User.cpp ./Models/ClassWorker/Worker.cpp ./Models/ClassProvider/Provider.cpp ./Models/ClassProduct/Product.cpp

int Production()
{

    myVector<Product> products{};

    std::function<int()> funcPrint = std::bind(&myVector<Product>::PrintAll, &products);
    std::function<int()> funcAdd = std::bind(&myVector<Product>::AddData, &products);
    std::function<int()> funcDelete = std::bind(&myVector<Product>::DeleteData, &products);
    std::function<int()> funcSort = std::bind(&myVector<Product>::SortByName, &products);
    std::function<int()> funcChange = std::bind(&myVector<Product>::ChangeData, &products);
    std::function<int()> funcSearch = std::bind(&myVector<Product>::SearchData, &products);

    Product::ReadProductsInfoFromTxt(products);

    CMenuItem items[ITEM_NUMBER_2]{
        CMenuItem{"Print product info", funcPrint},
        CMenuItem{"Add product info.", funcAdd},
        CMenuItem{"Delete product info.", funcDelete},
        CMenuItem{"Sort product info by cost.", funcSort},
        CMenuItem{"Change product info.", funcChange},
        CMenuItem{"Search info by type.", funcSearch}
    };
    CMenu menu("Product Menu", items, ITEM_NUMBER_2);
    while (menu.runCommand2()) {
    };

    Product::UpdateProductsInfoInTxt(products);

    return 3;

}

int main() {

    setlocale(LC_ALL, "RU");

    LogIn();

    CMenuItem items[ITEM_NUMBER]{
         CMenuItem{"Factory", Factory},
         CMenuItem{"Provider", Provide},
         CMenuItem{"Production", Production}
    };
    CMenu menu("Choosing", items, ITEM_NUMBER);

    while (menu.runCommand()) {
    }

    return 0;
}