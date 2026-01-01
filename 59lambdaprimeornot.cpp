
#include <iostream>
#include <vector>
using namespace std;

int main() {
vector<int>numb = {3,45,22,3,44,2,5};

auto check_prime = [](vector<int>&num){
    auto is_prime = [](int n){
        if(n<2) return false;
        for(int i = 2; i*i<=n; ++i){
            if(n%i == 0) return false;
        }
        return true;
    };
    for (int x : num)
    cout << x << (is_prime(x) ? " is Prime\n" : " is Not Prime\n");

};
    check_prime(numb);
    return 0;
}