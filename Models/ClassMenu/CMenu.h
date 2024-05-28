#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include "..\ClassMenuItem\CMenuItem.h"

using namespace std;

class CMenu {

public:
    CMenu(string, CMenuItem*, size_t);

    void print();

    int runCommand();
    int runCommand2();


private:
    int select{ -1 };
    size_t count{};
    string title{};
    CMenuItem* items{};
};