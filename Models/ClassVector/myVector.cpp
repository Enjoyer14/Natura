#pragma once
#include "myVector.h"

// template<typename T>
// myVector<T>::~myVector()
// {
//     delete[] data;
// }

template<typename T>
void myVector<T>::pushBack(T& value)
{
    if (size >= capacity) {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(new_capacity);
    }
    data[size++] = value;
}

template<typename T>
void myVector<T>::reserve(int new_capacity)
{
    if (new_capacity <= capacity) {
        return;
    }
    T* new_data = new T[new_capacity];
    for (int i = 0; i < size; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template<typename T>
void myVector<T>::remove(int index)
{
    if (index >= size) {
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template<typename T>
T& myVector<T>::operator[](int index)
{
    return data[index];
}

template<typename T>
int myVector<T>::getSize()
{
    return size;
}

template<typename T>
typename myVector<T>::Iterator myVector<T>::begin() {
    return Iterator(data);
}

template<typename T>
typename myVector<T>::Iterator myVector<T>::end() {
    return Iterator(data + size);
}



//работа с массивами
template<typename T>
int myVector<T>::PrintAll()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "#" << i + 1 << "-th\n";
        data[i].PrintInfo();
    }

    return 1;
}

template<typename T>
int myVector<T>::AddData()
{
    T buff;
    buff.T::AddInfo();
    this->pushBack(buff);

    return 2;
}

template<typename T>
int myVector<T>::DeleteData()
{
    int var = -1;
    std::string input = "-1";
    this->PrintAll();
    do {
        std::cout << "Choose ID: ";
        std::cin >> input;
        try
        {
            var = std::stoi(input);
        }
        catch (std::invalid_argument&) {
            std::cerr << "Error: Incorrect ID!" << std::endl;
            input.clear();
            var = -1;
        }
        catch (std::out_of_range&) {
            std::cerr << "Error: Out of range!" << std::endl;
            input.clear();
            var = -1;
        }
        catch (...) {
            std::cerr << "Error: Try again!" << std::endl;
            input.clear();
            var = -1;
        }
    } while (var < 0);

    var--;
    if (var > size)
    {
        std::cerr << "Error: out of array bounds\n";
    }
    else
    {
        this->remove(var);
    }
    return 3;
}

template<typename T>
int myVector<T>::ChangeData()
{
    int var = -1;
    std::string input = "-1";
    this->PrintAll();
    do {
        std::cout << "Choose ID: ";
        std::cin >> input;
        try
        {
            var = std::stoi(input);
        }
        catch (std::invalid_argument&) {
            std::cerr << "Error: Incorrect ID!" << std::endl;
            input.clear();
            var = -1;
        }
        catch (std::out_of_range&) {
            std::cerr << "Error: Out of range!" << std::endl;
            input.clear();
            var = -1;
        }
        catch (...) {
            std::cerr << "Error: Try again!" << std::endl;
            input.clear();
            var = -1;
        }
    } while (var < 0);

    var--;
    if (var > size)
    {
        std::cerr << "Error: out of array bounds\n";
    }
    else
    {
        this->data[var].T::ChangeInfo();
    }
    return 2;
}

template<typename T>
int myVector<T>::SearchData()
{
    T::SearchInfo(*this);
    return 3;
}

template<typename T>
int myVector<T>::SortByName()
{
    std::string input = "-1";
    int variant{ -1 };
    while (true) {
        do {
            std::cout << "1. Ascending. " << std::endl << "2. Descending. " << std::endl << "0. Exit. " << std::endl << "Select: ";
            std::cin >> input;
            try
            {
                variant = std::stoi(input);
            }
            catch (...) {
                std::cerr << "Error: Incorrect value!" << std::endl;
                input.clear();
                variant = -1;
            }
        } while (variant < 0);
        if (variant == 0) { return 1; };
        if (variant == 1 || variant == 2) break;
    }
    for (int l = 0; l < getSize() - 1; l++) {
        for (int j = 0; j < getSize() - l - 1; j++) {
            if (variant == 1 && data[j] < data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
            if (variant == 2 && data[j] > data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    return 4;
}



//итераторы
template<typename T>
myVector<T>::Iterator::Iterator(T* ptr)
    : m_ptr(ptr) {}

template<typename T>
typename myVector<T>::Iterator& myVector<T>::Iterator::operator++() {
    ++m_ptr;
    return *this;
}

template<typename T>
typename myVector<T>::Iterator myVector<T>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++m_ptr;
    return tmp;
}

template<typename T>
T& myVector<T>::Iterator::operator*() const {
    return *m_ptr;
}


template<typename T>
bool myVector<T>::Iterator::operator==(const Iterator& other) const {
    return m_ptr == other.m_ptr;
}

template<typename T>
bool myVector<T>::Iterator::operator!=(const Iterator& other) const {
    return m_ptr != other.m_ptr;
}

