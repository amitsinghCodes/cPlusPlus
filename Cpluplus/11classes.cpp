#include<iostream>
#include<string>

using namespace std;

class Car{
    private:
    int price = 100000; //encapsulation

    public:
    string brand;
    string model;
    int year;
    Car(){
        cout << "This is a constructor\n";}  //constructor

    int getprice(){
        return price;
    }
};

int main(){
    Car mycar;
    mycar.brand = "Ford";
    mycar.model = "Mustang";
    mycar.year = 1969;

    cout << mycar.brand << " " << mycar.model << " " << mycar.year << "\n";
    cout<< mycar.getprice();
    
    return 0;

}
// Output: Ford Mustang 1969