/*
Task: Implement a calendar that rejects bookings that overlap any existing booking. Each book(start,end) returns true if inserted, false otherwise. Intervals are half-open [start,end).
Constraints: up to 1e5 calls, 0 ≤ start < end ≤ 1e9
Example
book(10,20) -> true, book(15,25) -> false, book(20,30) -> true
Hint: map<int,int> start→end; use lower_bound(start) and check neighbor intervals for overlap.
*/

#include<iostream>
#include<map>
using namespace std;

class MyCalendar {
    
    map<int , int> booked;
    
public:
    bool book(int start, int end){
        map<int, int>::const_iterator it = booked.begin();
        for(; it != booked.end(); ++it){
            int s = it->first;
            int e = it->second;
            if(start < e && s < end)
            return false;
        }
        booked[start] = end;
        return true;
    }
};

int main(){
    MyCalendar o1;
    cout<<boolalpha;
    bool r1 = o1.book(10,20);
    bool r2 = o1.book(15,25);
    bool r3 = o1.book(20,30);
    
    cout<<r1<<endl;
    cout<<r2<<endl;
    cout<<r3<<endl;
}

