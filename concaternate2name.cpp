#include<iostream>
#include<string>

using namespace std;

int main(){
    string text1 = "Petronas ";
    string text2 = "F1 Racing";
    string text3;

    string f1team = text1 + text2;
    cout << f1team<< endl;
    cout << text1.append(text2) << endl;
    cout << "Lenth is  " << f1team.length() << endl;
    cout << f1team[f1team.length() - 1] <<endl; // will printlast letter of word
    cout << f1team.at(f1team.length() - 1) <<endl; // will printlast letter of word
    getline(cin, text3);
    return 0;
}