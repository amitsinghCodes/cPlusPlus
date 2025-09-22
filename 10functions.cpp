#include<iostream>
#include<string>
#include<vector>

using namespace std;

void defaultfunction(int a = 10);
void modifystr(string &str);

void defaultfunction(int a){
    cout << "This is a default function\n" << a << "\n";
}

void modifystr(string &str){
    str += "World!";
    }

    void printarray(int mynums[5]){
        for(int i = 0; i < 5; i++){
            cout << mynums[i] << "\n";
        }
    }


    int myfunc(int x, int y){    //function overloading
        return x + y;
    }

    double myfunc(double x, double y){
        return x + y;
    }

    int factorialrecursion(int n){
        if(n == 1){
            return 1;
        }
        else{
            return n * factorialrecursion(n - 1);
        }
    }

int  main()
{
    defaultfunction();
    defaultfunction(20);

    string greetings = "Hello ";
    cout << "Before modification: " << greetings << "\n";
    modifystr(greetings);
    cout << "After modification: " << greetings << "\n";

    int mynums[5] = {1, 2, 3, 4, 5};
    printarray(mynums);


    cout << myfunc(10, 20) << "\n";
    cout << myfunc(10.57, 20.5) << "\n";

    cout << factorialrecursion(5) << "\n";

    return 0;
}