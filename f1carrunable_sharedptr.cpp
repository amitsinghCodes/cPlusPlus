
#include <iostream>
#include<memory>

using namespace std;

class tyre{
    public:
    
    shared_ptr<bool>istyrepunc;
    
    tyre(): istyrepunc(make_shared<bool>(false)){}
    
    
};

class f1car{
    private:
    
    shared_ptr<tyre>t1;
    shared_ptr<tyre>t2;
    shared_ptr<tyre>t3;
    shared_ptr<tyre>t4;
    
    public:
    f1car(): t1(make_shared<tyre>()), t2(t1), t3(t1), t4(t1){}
    
    shared_ptr<tyre> getwheel(){
        return t1;
    }
    
    void punctyre(){
        *(t1->istyrepunc) = true;
        cout<<"Tyre Punc";
    }
    
    bool iscarrunable(){
        return !(*t1->istyrepunc);
    }
    
    void ispuncstatus(bool status){ 
        *(t1->istyrepunc) = status;
    }
    
};


int main() {
tyre t;
f1car f;

shared_ptr<tyre>wheel(f.getwheel());
f.ispuncstatus(false);

cout<<"is car runable: "<<(f.iscarrunable() ? "Yes": "No")<<endl;
    return 0;
}