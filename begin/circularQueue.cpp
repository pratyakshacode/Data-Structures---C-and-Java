#include<bits/stdc++.h>
using namespace std;

class circularQueue{
    int * arr;
    int size, front, rear;

public:

    circularQueue(int s){
        this -> size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }

    void push(int data){

        //checking for the overflow 
        if(front == 0 && rear == size-1 || ((rear == front-1) % (size-1))){
            cout << "Queue Overflowed" << endl;
        }
        else if(rear == -1 && front == -1){
            rear = front = 0;
        }
        //going to insert the first element or the rear reaches the end
        else if(rear == size-1){
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = data;

    }

    void pop(){

        if(front == -1){
            cout << "Nothing present .. Underflow" << endl;
        }
        else {

            int element = arr[front];
            arr[front] = -1;

            if(front == size -1) front = 0;
            else if(front == rear) {
                front = rear = -1;
            }
            else {
                front++;
            }

            cout << element << endl;
        }

    }

    bool isEmpty(){

        if(front == -1) return true;
        else return false;
    }

    void frontItem(){
        if(front == -1){
            cout << "Queue Underflowed >> Nothing Present" << endl;
        }
        else{
            cout << arr[front] << endl;
        }
    }
};

int main(){

    circularQueue q(5);
    q.push(12);
    q.frontItem();
    q.push(10);
    q.frontItem();

    q.push(100);
    q.frontItem();
    q.push(51);
    q.frontItem();
    q.push(29);
    q.frontItem();

    q.push(26);
    q.frontItem();

    q.pop();
    q.push(23);
    q.frontItem();
    q.push(3);


    return 0;
}