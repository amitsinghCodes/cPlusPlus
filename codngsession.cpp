#include<iostream>
#include<list>
#include<thread>
#include<condition_variable>
using namespace std;

/*
--------------------------------------
name=”Srinivasan”
age=35
gender=”Male”
--------------------------------------
name=”Shailaja”
age=41
gender=”Female”
*/

/*
Print numbers 1 to 100 
output screen
howver
thread1 - odd
thread2 - even
*/
/*
The sensor sends raw 8-bit unsigned temperature data (0–255).
    • The system needs to:
    • Store the raw value in memory.
    • Convert it to Celsius, using the formula:
      Celsius= ((raw x 500)/ 255) – 100
      
*/

void tempconv(unsigned int numb){
    double cel = 0.00;
    cel = ((static_cast<double>(numb) * 500)/ 255) - 100;
    cout<<cel;
}

int main(){
    unsigned int temp;
    cin>> temp;
    tempconv(temp);

    return 0;
}