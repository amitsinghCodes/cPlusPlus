#include<iostream>
#include<cstring>
#include<memory>


using namespace std;
class tyre;
class Car{

    public:
    shared_ptr<string> carname;

    weak_ptr<tyre>c1;

public:
    void set_ptr(shared_ptr<tyre> t) {
        c1 = t;
    }

    

void f1(){
    unique_ptr<int> p1(new int(10));
    unique_ptr<int> p2 ;

    cout<<*p1<<endl;
    // unique_ptr<int> p2 = p1; // Error: can't copy unique_ptr

    p2 = move(p1); //Transfer onership
    if(p1 == nullptr){
        cout<<"p1 is null and not the owner of 10."<<endl;
    }

    cout<<*p2<<endl;
    // cout<<*p1<<endl; // Error: p1 is null

}

~Car(){
    cout<<"desctor of car"<<endl;
}

};


class tyre{

    private:

    shared_ptr<Car>wheel1;
    shared_ptr<Car>wheel2;
    shared_ptr<Car>wheel3;
    shared_ptr<Car>wheel4;

    public:

    void set_ptr(shared_ptr<Car> c){
        t1 = c;
    }

    weak_ptr<Car>t1;

    tyre(){
        wheel1 = make_shared<Car>();
    }
    
    shared_ptr<Car> getwheel1(){
        return wheel1;
    }

    ~tyre(){
        cout<<"desctor of tyre"<<endl;
    }
    
};

void f2(){
    shared_ptr<Car> cc(new Car());
    shared_ptr<tyre> tt(new tyre());
    cc->set_ptr(tt);
    tt->set_ptr(cc);

    cout<<cc.use_count()<<"using shared pointer to check cycle dependeccy"<<endl;
    cout<<tt.use_count();
}

int main(){
    Car c;
    c.f1();
    tyre t;

    shared_ptr<int> p1(new int(20));
    shared_ptr<int>p2(p1);
    cout<<*p1<<endl;
    cout<<*p2<<endl;
    cout<<p1.get()<<endl;
    cout<<p2.get()<<endl;
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;


    shared_ptr<Car>wheel(t.getwheel1());
    cout<<wheel.use_count()<<endl;



    shared_ptr<int> p3(new int(50));
    weak_ptr<int> p4(p3);
    cout<<p3.use_count()<<endl;
    cout<<p4.use_count()<<endl;
    cout<<*p3<<endl;
    cout<<*p4.lock()<<endl;
    p3.reset();
    cout<<p3.use_count()<<endl;
    cout<<p4.use_count()<<endl;



    f2();

    return 0;

}