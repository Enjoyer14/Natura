
#pragma once
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class myVector {
public:
    // ������������ � ����������
    myVector() : data(nullptr), capacity(0), size(0) {}

    // ~myVector();

    // ��������
    class Iterator {
    public:

        Iterator(T* ptr);

        Iterator& operator++();

        Iterator operator++(int);

        T& operator*() const;

        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

    private:
        T* m_ptr;
    };

    // ������
    void pushBack(T& value);

    void reserve(int new_capacity);

    void remove(int index);

    T& operator[](int index);

    int getSize();

    //���������
    Iterator begin();
    Iterator end();

    //������� ������ � ������������ ��������
    int PrintAll();

    int AddData();

    int DeleteData();

    int ChangeData();

    int SearchData();

    int SortByName();

private:
    T* data;
    int size;
    int capacity;

};

#include "myVector.cpp"
