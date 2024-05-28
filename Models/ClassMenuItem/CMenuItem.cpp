#include "CMenuItem.h"

CMenuItem::CMenuItem(string name, Function function) : item_name(name), funct(function) {}
CMenuItem::CMenuItem(string name, std::function<int()> function) : item_name(name), func(function) {}

void CMenuItem::print() 
{
    std::cout << item_name;
}

int CMenuItem::run()
{
   return funct();
}

int CMenuItem::run2()
{
    return func();
}



