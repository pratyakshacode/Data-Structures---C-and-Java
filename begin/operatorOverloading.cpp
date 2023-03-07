#include<bits/stdc++.h>
using namespace std;

class A{

    public:
    int a;
    

    void operator+ (A &obj){
        cout << "After overloading : " << this-> a - obj.a << endl;
    }

    void operator*(A &obj){
        cout << "We have overloaded * : " << this -> a << endl;
    }
    void operator/(A & obj){
        cout << "we have overloaded / : " << this-> a * obj.a << endl;
    }
    void operator()(){
        cout << "we have overloaded () : " <<  this-> a << endl;
    }

};
int main(){

A obj1, obj2;
obj1.a = 5;
obj2.a = 15;
obj1 + obj2;
obj1 * obj2;
obj1 / obj2;
obj1();
obj2();
    return 0;
}