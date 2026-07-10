#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int size)
{
    this->SIZE = size;
    this->S = new int[this->SIZE];
    this->top = -1;
}

void Stack::operator+(int item)
{
    this->S[++this->top] = item;
}

void Stack::operator-()
{
    this->top--;
}

int Stack::peek()
{
    return this->S[this->top];
}

void Stack::print_Stack()
{
    cout << "\nCurrent Stack: ";
    for (int i = 0; i <= this->top; i++)
    {
        cout << this->S[i] << " ";
    }
    cout << endl;
}