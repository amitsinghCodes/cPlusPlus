
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

condition_variable cv;
mutex mtx;
int counter = 1;

void printnum(bool isodd){
    while(counter <= 100){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&] {return (counter % 2 == 1) == isodd;});
        if(counter <= 100){
            cout<<counter++<<" ";
        }
        cv.notify_all();
    }
}

int main() {
    thread t1(printnum, true);
    thread t2(printnum, false);
    
    t1.join();
    t2.join();
    
    return 0;
}


/*
////////////////////////////////     METHOD 2      /////////////////////////////////////
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

condition_variable cv;
mutex mtx;
int counter = 1;
bool counterodd = true;

void printodd(){
    while(counter < 100){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{return counter%2 == 1;});
        cout<<counter<<" "<<endl;
        counter++;
        counterodd = false;
        cv.notify_all();
    }
}

void printeven(){
    while(counter < 100){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{return counter%2 == 0;});
        cout<<counter<<" "<<endl;
        counter++;
        counterodd = true;
        cv.notify_all();
    }
}

int main() {
    thread t1(printodd);
    thread t2(printeven);
    
    t1.join();
    t2.join();
    
    return 0;
}
*/