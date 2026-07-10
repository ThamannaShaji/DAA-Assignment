class Queue
{
    int *q;
    int front;
    int rear;
    int SIZE;

public:
    Queue(int);

    void operator+(int);
    void operator-();

    int peek();
    void print_Queue();
};
