#include "MyArray.h"

ostream& operator<<(ostream& os, const MyArray obj)
{
    //size_t size
    //int* massiv
    for (int i = 0; i < obj.size; i++)
        os << obj.masiv[i];
    return os;
}

MyArray::MyArray()
{
    size = 0;
    masiv = nullptr;
    index = 0;
}

MyArray::MyArray(const size_t size)
{
    this->size = size;
    this->masiv = new int[this->size];
}

MyArray::MyArray(const MyArray& obj)
{
    this->size = obj.size;
    this->masiv = new int[obj.size];
    for (auto i = 0; i < obj.size; i++)
        this->masiv[i] = obj.masiv[i];
}

MyArray::MyArray(MyArray&& obj)
{
    this->size = obj.size;
    this->masiv = obj.masiv;
    obj.masiv = nullptr;
}

MyArray MyArray::operator=(const MyArray& obj)
{
    this->size = obj.size;
    if (this->masiv)
        delete[] this->masiv;
    this->masiv = new int[obj.size];
    for (auto i = 0; i < obj.size; i++)
        this->masiv[i] = obj.masiv[i];
    return *this;
}

MyArray MyArray::operator=(MyArray&& obj)
{
    this->size = obj.size;
    if (this->masiv)
        delete[] this->masiv;
    this->masiv = obj.masiv;
    obj.masiv = nullptr;
    return *this;
}

MyArray MyArray::operator+(const MyArray& obj) const
{
    MyArray extArray(this->size + obj.size);
    for (auto i = 0; i < this->size; i++)
        extArray.masiv[i] = this->masiv[i];
    for(auto i = this->size; i < this->size + obj.size; i++)
        extArray.masiv[i] = obj.masiv[i];
    return extArray;
}

void MyArray::begin()
{
    this->index= 0;
}

bool MyArray::end() const
{
    if (this->index < this->size)
        return true;
    else
        return false;
}

void MyArray::next()
{
    this->index++;
}

int MyArray::get() const
{
    return this->masiv[index];
}

void MyArray::set(const int data, const size_t pos)
{
    this->masiv[pos] = data;
}

void MyArray::resize(const size_t new_size)
{
    int* newArray = new int[new_size];
    for (int i = 0; i < this->size; i++)
    {
        newArray[i] = this->masiv[i];
    }
    this->masiv = newArray;
    this->size = new_size;
}

void MyArray::revers()
{
    int temp{ 0 };
    for (int i = 0, j = this->size-1; i < j; i++, j--)
    {
        temp = this->masiv[j];
        this->masiv[j] = this->masiv[i];
        this->masiv[i] = temp;
    }
}

void MyArray::sort()
{
    int temp{ 0 };
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size - 1; j++)
        {
            if (this->masiv[j] > this->masiv[i])
            {
                temp = this->masiv[j];
                this->masiv[j] = this->masiv[i];
                this->masiv[i] = temp;
            }
        }
    }
}

size_t MyArray::lenght() const
{
    return size_t();
}

MyArray::~MyArray()
{
    delete[] this->masiv;
}
