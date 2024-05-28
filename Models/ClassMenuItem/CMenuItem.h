#pragma once
#include <iostream>
#include <string>
#include "..\ClassProduct\Product.h"
#include "..\ClassWorker\Worker.h"
#include "..\ClassProvider\Provider.h"
#include "..\ClassVector\myVector.h"
#include <functional>

using namespace std;

class CMenuItem {

public:

    typedef int (*Function)();

    CMenuItem(string, Function);
    CMenuItem(string, std::function<int()>);

    Function funct{};
    std::function<int()> func{};

    string item_name{};
    void print();

    int run();
    int run2();


};

