// it is also called deque

#include <bits/stdc++.h>
using namespace std;

class Deque
{

    int *arr;
    int size, front, rear;

public:
    Deque(int s)
    {
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }

    void pushback(int data)
    {

        // checking for the overflow
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue Overflowed" << endl;
        }
        // going to insert 1st element
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = data;
    }
    void pushfront(int data)
    {

        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue Overflowed" << endl;
        }
        // going to insert the first element into the queue
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        arr[front] = data;
    }

    void popback()
    {

        // checking for the underflow
        if (rear == -1)
        {
            cout << "Nothing Present >> Underflowed" << endl;
        }

        else
        {
            int element = arr[rear];
            arr[rear] = -1;

            if (rear == 0)
                rear = size - 1;
            else if (front == rear)
                front = rear = -1;
            else
            {
                rear--;
            }

            cout << element << endl;
        }
    }
    void popfront()
    {

        if (front == -1)
        {
            cout << "Nothing Present >> underflow" << endl;
        }

        else
        {
            int element = arr[front];
            arr[front] = -1;

            if (front == size - 1)
                front = 0;
            else if (front == rear)
                front = rear = -1;
            else
            {
                front++;
            }

            cout << element << endl;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void isfront()
    {

        if (front == -1)
        {
            cout << "Nothing present" << endl;
        }

        else
            cout << arr[front] << endl;
    }
};
int main()
{

    Deque d(5);
    d.pushfront(5);

    d.pushback(7);
    d.popback();
    d.pushfront(16);
    d.popback();
    d.pushback(20);
    d.popback();
    d.pushfront(1);
    d.popback();
    d.pushback(27);
    d.popback();
    if (d.isEmpty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;
    d.isfront();

    return 0;
}