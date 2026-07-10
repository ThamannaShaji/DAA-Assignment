#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int SIZE)
{
    this->SIZE = SIZE;
    this->q = new int[SIZE];
    this->front = -1;
    this->rear = -1;
}

void Queue::operator+(int item)
{
    if(rear == SIZE - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }

    if(front == -1)
        front = 0;

    q[++rear] = item;
}

void Queue::operator-()
{
    if(front == -1 || front > rear)
    {
        cout << "Queue Underflow\n";
        return;
    }

    front++;
}

int Queue::peek()
{
    if(front == -1 || front > rear)
    {
        cout << "Queue Empty\n";
        return -1;
    }

    return q[front];
}

void Queue::print_Queue()
{
    if(front == -1 || front > rear)
    {
        cout << "\nQueue Empty";
        return;
    }

    cout << "\nCurrent Queue: ";

    for(int i = front; i <= rear; i++)
        cout << q[i] << " ";
}