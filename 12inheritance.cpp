#include<iostream>
#include<string>

using  namespace std;

class Vehicle {
    public:
    string brand = "Ford";
    void bhoop(){
        cout<<"Bhoop Bhoop \n"; //Overriding
    }
};

class sportsCar{
    public:
    string model = "Jaguar";
    void bhoop(){
        cout<<"Bhoop Bhoop2 \n";} 
    void sports(){
        cout<<"Eracing \n";
    }
};

//Derived Class

class EV: public Vehicle{ //Single inheritance
    public:
    string model = "Bajaj";
    void bhoop(){
        cout<<"Bhoop Bhoop Bhoop \n"; //Overriding
    }
};

class Bike: public EV{ //Multilevel inheritance
    public:
    string bname ="Torq";
    void bhoop(){
        cout<<"Bhoop Bhoop3 \n";} //Overriding
    Bike(){
    cout << bname <<endl;
    }
};

class event:public Vehicle, public sportsCar{ //Multiple inheritance
    public:
    string eventname ="Racing event \n";
    void bhoop(){
        cout<<"Bhoop Bhoop4 \n";} //Overriding
    event(){
        cout<<eventname;
    }
};

int main(){
    
    EV myEV;
    myEV.bhoop();

    cout<<myEV.brand + " " + myEV.model<<endl;
    Bike myBike;
    myBike.bhoop();
    event myevent;
    myevent.bhoop();
    
    return 0;
}