
#include <iostream>
using namespace std;
class myclass{
    int x;
    int* max;
    char m;
    char * ch;
    
    public:
    
    myclass(): x(0), max(nullptr), m(' '), ch(nullptr){
        cout<<"default \n";
    }

    int mylen(const char* cc){
        int len = 0; while(cc[len] != '\0') ++len; return len;
    }

    myclass(int xd, int mx, char c, const char* ct){
        x = xd;
        max = new int(mx);
        m = c;
        int len = mylen(ct);
        ch = new char[len + 1];
        for(int i = 0 ;i<=len; ++i){
        ch[i] = ct[i];
        }
    }
    
    myclass(myclass& other){
        x = other.x;
        max = new int(*other.max);
        m = other.m;
        int len = mylen(other.ch);
        ch = new char[len + 1];
        for(int i = 0 ;i<=len; ++i){
        ch[i] = other.ch[i];
    }
    }
    
    myclass& operator=(myclass& other){
         x = other.x;
        max = new int(*other.max);
        m = other.m;
        other.m = ' ';
        int len = mylen(other.ch);
        ch = new char[len + 1];
        for(int i = 0 ;i<=len; ++i){
        ch[i] = other.ch[i];
    }
    other.ch = nullptr;
    return *this;
    }

    myclass(myclass&& other){
        x = other.x;
        other.x = 0;
        max = new int(*other.max);
        *other.max = 0;
        m = other.m;
        int len = mylen(other.ch);
        ch = new char[len + 1];
        for(int i = 0 ;i<=len; ++i){
        ch[i] = other.ch[i];
        }
    }

    ~myclass(){
        delete max;
        delete[] ch;
    }
    
    friend ostream& operator<<(ostream& out, myclass& obj);
};

ostream& operator<<(ostream& out, myclass& obj){
    out<<obj.x<<endl;
    out<<*obj.max<<endl;
    out<<obj.m<<endl;
    out<<obj.ch;
    return out;
}
int main() {
    myclass obj1;
    myclass obj(1, 20, 'a', "aaaa");
    cout<<obj;
    myclass obj2 = obj;
    cout<<obj2;
    myclass obj3;
    obj3 = obj2;
    cout <<"obj3"<<obj3;

    return 0;
}