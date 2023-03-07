#include<bits/stdc++.h>
using namespace std;

class Stack{
    
    int * arr;
    int top;
    int size;

    public:

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data){
        if(size - top > 1){
            top ++;
            arr[top] = data;
        }
        else {
            cout << "Oops .. Stack Overflow" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            cout << arr[top] << endl ;
            top --;
        }
        else{
            cout << "Oops .. Stack Underflow" << endl;
        }
    }

    bool isEmpty(){
        if(top = -1) return true;
        return false;
    }

    void atTop(){
        if(top >= 0)
        cout << arr[top] << endl;
        else cout << "Stack is Empty" << endl;
    }

    void deleteStack(){
        delete [] arr;
    }
};


 

class TwoStack{
    private:
    int * arr, top1, top2, size;

    public:
    TwoStack(int size){
        this -> size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2-top1 > 1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout << "Oops..Stacks overflowed" << endl;

        }
    }

    void push2(int data){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout << "Oops..Stacks overflowed" << endl;

        }
    }

    void pop1(){
        if(top1 >= 0){
            cout << arr[top1];
            top1--;
        }
        else{
            cout << "Oops.. Stack Underflow" << endl;
        }
    }

    void pop2(){
        if(top2  < size){
            cout << arr[top2];
            top2++;
        }

        else{
            cout << "Oops.. Stack Underflow" << endl;
        }
    }

    void atTop1(){
        if(top1 >= 0)
        cout << arr[top1];
    else{
        cout << "Stack is Empty" << endl;
    }}

    void atTop2(){
 if(top2 < size)
        cout << arr[top2];
    else{
        cout << "Stack is Empty" << endl;
    
    }}
    };
int main(){

   /* Stack s(5);

    s.push(22);
    s.push(23);
    s.push(24);
    s.atTop();
    s.pop();
    s.pop();
    s.pop();
    s.atTop();
    
    if(s.isEmpty()){
        cout << "Empty";
    }
    else cout << "Not Empty";
    */

   TwoStack s(5);
   s.push1(10);
   s.push1(20);
   s.push1(30);

   s.push2(30);
   s.push2(40);
   s.push2(50);  // stack2 has overflowed
   s.push1(0);
   s.atTop1();
   s.atTop2();
    return 0;
}