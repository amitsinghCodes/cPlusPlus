#include<iostream>

using namespace std;

int main()
{
    int listNums[5] = {1,2,3,4,5};
    for(int i: listNums)
    cout << i <<endl;
    return 0;
}