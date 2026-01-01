#include<iostream>
#include<string>
// condition ? true : flase;
using  namespace std;

int main()
{
    int timeis = 20;
    string  result;
    if(timeis < 18)
    cout<< "Good day"<<endl;
    else
    cout<< "Good Evening"<<endl;
    result = (timeis < 18) ?  "Good Day." : "Good Evening.";
    cout <<result;
    return 0;
}