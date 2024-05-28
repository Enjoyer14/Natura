#include "CMenu.h"

CMenu::CMenu(string title, CMenuItem* items, size_t count) : title(title), items(items), count(count) {}

void CMenu::print() {
    for (size_t i{}; i < count; ++i) {
        std::cout << i + 1 << ".";
        items[i].print();
        std::cout << std::endl;
    }
    std::cout << "0.Exit" << std::endl;
}

int CMenu::runCommand() {
    print();

    std::string user_input = "-1";

    do {
        std::cout << "\nSelect: ";
        std::cin >> user_input;
        
        try {
            select = std::stoi(user_input); 
        }
        catch (std::invalid_argument&) {
            std::cerr << "Error: Incorrect argument!" << std::endl;
            user_input.clear(); 
            select = -1;
        }
        catch (std::out_of_range&) {
            std::cerr << "Error: Out of range!" << std::endl;
            user_input.clear(); 
            select = -1;
        }

    } while (select < 0 || select > 3); 



    if (select <= 0) {
        return 0;
    }
    return items[select - 1].run();
}

int CMenu::runCommand2() {
    print();
    std::string user_input = "-1";
    do {
        std::cout << "\nSelect: ";
        std::cin >> user_input;

        try {
            select = std::stoi(user_input);
        }
        catch (std::invalid_argument&) {
            std::cerr << "Error: Incorrect argument!" << std::endl;
            user_input.clear();
            select = -1;
        }
        catch (std::out_of_range&) {
            std::cerr << "Error: Out of range!" << std::endl;
            user_input.clear();
            select = -1;
        }

    } while (select < 0 || select > 6);
    if (select <= 0) {
        return 0;
    }
    return items[select - 1].run2();
}
