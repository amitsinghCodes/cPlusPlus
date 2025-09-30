#include<iostream>
using namespace std;


class increment{
    int imaginary;
    int real;
    
    public :
    
    increment(int x, int y){
        imaginary = x;
        real = y;
    }
  //  increment(increment& other){
   //     imaginary = other.imaginary;
  //      real = other.real;
  //  }
    
    increment& operator++(){
        ++imaginary;
        ++real;
        return *this;
    }

    increment operator++(int){    
        increment old = *this;
        ++imaginary;
        ++real;
        return old;   //By convention (and the STL’s expectations), prefix returns a reference to the incremented object, while postfix returns a copy of the old value (the value before increment).
    }
    
    friend ostream& operator<<(ostream& out, const increment& obj);
};

ostream& operator<<(ostream& out, const increment& obj){
    out<<obj.imaginary;
    out<<" "<<obj.real;
    return out;
}

int main(){
    increment obj(2,4);
    obj++;
    cout<<obj<<endl;
    ++obj;
    cout<<obj;
    
    return 0;
}