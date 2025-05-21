// Online C++ compiler to run C++ program online
#include <iostream>
#include<cstring>
using namespace std;
class amp{
    public :
    char* ch;
    int len;
    
    amp (): ch(nullptr), len(0) {
        cout<<"Defualt constructor"<<endl;
    }
    
    
    // Constructor (const char*)
    amp(const char* str) {
        len = strlen(str);
        ch = new char[len + 1];
        strcpy(ch, str);
        cout << ch << " " << len << endl;
    }
    
    // Constructor (const string&)
    amp(const string& str){
        len = str.length();
        ch = new char[len + 1];
        strcpy(ch, str.c_str());
        len = str.length();
        cout<<ch<<" "<<len<<endl;
    }
    
    // Copy constructor
    amp(const amp& other){
        len = other.len;
        ch = new char[len + 1];
        strcpy(ch,other.ch);
        cout<<"Copy constructor"<<" "<<ch<<" " <<len<<endl;
    }
    
    // Copy assignment operator
    amp& operator=(const amp& other){
        if(this != &other){
            delete ch; //free existing memory
            len = other.len;
            ch = new char[len+1];
            strcpy(ch,other.ch);
            cout<<"Copy assignmnet constructor"<<" "<<ch<<" " <<len<<endl;
        }
        return *this;
    }

    amp operator+(const amp& other){
        int newLem = len + other.len;
        char* newCh = new char[newLem + 1];
        strcpy(newCh, ch);
        strcat(newCh, " ");
        strcat(newCh, other.ch);
        cout<<"Addition operator called :";
        return amp(newCh);
    }

    // Move constructor
    amp(amp&& other){
        len = other.len;
        ch = other.ch;
        other.len = 0;
        other.ch = nullptr;
        cout<<"Move constructor"<<" "<<ch<<" " <<len<<endl;
    }

    amp& operator=(amp&& other){
        if(this != &other){
            delete ch;
            ch = other.ch;
            len = other.len;
            other.ch = nullptr;
            other.len = 0;
            cout<<"Move assignment operator"<<" "<<ch<<" " <<len<<endl;
        }
    }

    friend ostream& operator<<(ostream& out, const amp& str);
    friend istream& operator>>(istream& in, amp& str);

    ~amp(){
        delete ch;
        cout<<"Destructor"<<endl;
    }
    
};

ostream& operator<<(ostream& out, const amp& str){ //operator overloading
    out<<str.ch;
    return out;
}

istream& operator>>(istream& in, amp& str){  //operator overloading
    char temp[100];
    in>>temp;
    str.len = strlen(temp);
    str.ch = new char[str.len + 1];
    strcpy(str.ch , temp);
    cout<<str.ch<<" "<<str.len<<endl;
    return  in;
}

int main() {
    // Write C++ code here
    amp str0; // Default constructor
   amp str1= "Hello"; // Constructor (const char*)
   amp str2 = string("World"); // Constructor (const string&)
   
   amp  str3 = str1; // Copy constructor
   
   str3 = str2; // Copy assignment operator

   amp str4 = "Thanks ";
   amp str5 = str4 + str3; // Addition operator

   cout<<str2<<endl;  //operator overloading
   cin>>str0;

   amp str6 = move(str5); // Move constructor
    str6 = move(str4); // Move assignment operator
   
    return 0;
}