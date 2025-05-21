#include<iostream>
#include<vector>
#include<string>

using namespace std;

int  main()
{
    string cars[] = {"Maruti", "Mahindra", "TATA"};// size is  3
    for(string i : cars){
    cout<< i<<endl;}

    vector<string> bikes = {"Hero", "Bajaj", "Harley", "Royal Enfield"};
    bikes.push_back("Ducati");
    for(string k : bikes)
    cout<< k << endl;
    cout<<sizeof(bikes)/sizeof(bikes[0]); // doesnotworksforvector

    int ages[7] = {20,22,24,25,21,26,29};

    int length = sizeof(ages)/sizeof(ages[0]);

    int largestage = ages[0];

    for(int i: ages)
    {
        if(largestage < i){
            largestage = i;
        }
    }
    cout<<"Largest  age :" <<largestage<< endl;
    return  0;
}