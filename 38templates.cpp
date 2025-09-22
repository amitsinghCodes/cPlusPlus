#include<iostream>

using namespace  std;

template <typename T> T myMax(T a, T b){
    return (a > b) ? a : b;

}

template <typename T> class myclass{
    public :  
    T x;
    T y;

    myclass(T val1,  T val2): x(val1) , y(val2) {}
};

int main(){

    cout << myMax<int>(15,10);

    return  0;
}