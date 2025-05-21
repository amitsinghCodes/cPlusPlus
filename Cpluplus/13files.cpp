#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
    ofstream Myfile("13files.txt");
    Myfile<<"This is a file created using C++\n";
    Myfile<<"5555 \n";
    Myfile<<"4444 \n";
    Myfile.close();

    ifstream MyReadFile("13files.txt");
    string myText;
    int sum = 0;
    while(getline(MyReadFile, myText)){
        stringstream ss(myText); //convert line to a stream
    int x;
    while(ss >> x){
        sum = x + sum;  //extract numbers from line
    }
    }
    
    MyReadFile.close();
    cout << sum;
    return 0;
}