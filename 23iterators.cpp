#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    vector<string> cars = {"BMW", "Mahindra", "Mercedes", "Toyota"};

    vector<string>::iterator it;

    for(it = cars.begin(); it != cars.end(); it++){
        cout<<*it<<endl;
    }

    cars.insert(cars.begin(), "Jeep");
    cars.insert(cars.end(), "Ford");

    auto it1 = cars.begin(); //alternative way to declare iterator
    cout<<*it1<<endl;   //Jeep


    for(it = cars.begin(); it != cars.end(); it++){
        cout<<*it<<endl;
    }

    vector<int> numbers = {1, 7, 3, 5, 9, 2};

  // Sort numbers numerically  order
  sort(numbers.begin(), numbers.end());

  for (int num : numbers) {
    cout << num << "\n";
  }

  vector<int> numbers2 = {1, 7, 3, 5, 9, 2};

  // Sort numbers numerically in reverse order
  sort(numbers2.rbegin(), numbers2.rend());

  for (int num : numbers2) {
    cout << num << "\n";
  }

    return  0;
}