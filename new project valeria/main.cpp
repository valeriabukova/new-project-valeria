//
//  main.cpp
//  new project valeria
//
//  Created by Valeria  Bukova on 01.10.2024.
//



#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* data;
    int size;

public:
    DynamicArray(int s = 0) : size(s)
    {
        data = new int[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = 0;
        }
    }

    DynamicArray(const DynamicArray& other) : size(other.size)
    {
        data = new int[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    DynamicArray operator+(int n)
    {
        DynamicArray temp(size + n);
        for (int i = 0; i < size; ++i)
        {
            temp.data[i] = data[i];
        }
        return temp;
    }

    DynamicArray operator-(int n)
    {
        if (size <= n)
        {
            cout << "Error: The size of the array is less than or equal to the number of deleted elements!" << endl;
            return *this;
        }
        DynamicArray temp(size - n);
        for (int i = 0; i < temp.size; ++i)
        {
            temp.data[i] = data[i];
        }
        return temp;
    }

    DynamicArray operator*(int factor)
    {
        DynamicArray temp(size);
        for (int i = 0; i < size; ++i)
        {
            temp.data[i] = data[i] * factor;
        }
        return temp;
    }

    DynamicArray operator-(const DynamicArray& other)
    {
        int newSize = size > other.size ? size : other.size;
        DynamicArray temp(newSize);
        for (int i = 0; i < newSize; ++i)
        {
            temp.data[i] = (i < size ? data[i] : 0) - (i < other.size ? other.data[i] : 0);
        }
        return temp;
    }

    DynamicArray operator+(const DynamicArray& other)
    {
        DynamicArray temp(size + other.size);
        for (int i = 0; i < size; ++i)
        {
            temp.data[i] = data[i];
        }
        for (int i = 0; i < other.size; ++i)
        {
            temp.data[size + i] = other.data[i];
        }
        return temp;
    }

    DynamicArray& operator++()
    {
        DynamicArray temp(size + 1);
        for (int i = 0; i < size; ++i)
        {
            temp.data[i] = data[i];
        }
        temp.data[size] = 0;
        *this = temp;
        return *this;
    }

    DynamicArray& operator--()
    {
        if (size <= 0) {
            cout << "Error: The size of the array cannot be reduced below 0!" << endl;
            return *this;
        }
        DynamicArray temp(size - 1);
        for (int i = 0; i < temp.size; ++i)
        {
            temp.data[i] = data[i];
        }
        *this = temp;
        return *this;
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray a(5);
    for (int i = 0; i < 5; ++i)
    {
        a = a + 1;
    }

    cout << "array a: ";
    a.print();

    DynamicArray rez = a + 10;
    cout << "a + 10: ";
    rez.print();

    DynamicArray rez1 = a - 2;
    cout << "a - 2: ";
    rez1.print();

    DynamicArray rez2 = a * 2;
    cout << "a * 2: ";
    rez2.print();

    DynamicArray b(5);
    for (int i = 0; i < 5; ++i)
    {
        b = b + (i + 1);
    }

    cout << "array b: ";
    b.print();

    DynamicArray rez3 = a - b;
    cout << "a - b: ";
    rez3.print();

    DynamicArray rez4 = a + b;
    cout << "a + b: ";
    rez4.print();

    ++rez;
    cout << "++rez: ";
    rez.print();

    --rez;
    cout << "--rez: ";
    rez.print();

    return 0;
}
