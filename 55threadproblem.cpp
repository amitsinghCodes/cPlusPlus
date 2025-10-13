
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

condition_variable cv;
mutex mtx;
int counter = 1;


void print1to50(){
    while(counter < 100){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{return counter < 51;});
        for(int i = counter; i< 51; i++){
        cout<<"thread 1 :"<<counter<<" "<<endl;
        counter++;
        }
        cv.notify_all();
    }
}

void print51to100(){
    while(counter < 100){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]{return (counter > 50 && counter < 100);});
        for(int i = counter; i<= 100; i++){
        cout<<"thread 2 :"<<counter<<" "<<endl;
        counter++;}
        cv.notify_all();
    }
}

int main() {
    thread t1(print1to50);
    thread t2(print51to100);
    
    t1.join();
    t2.join();
    
    return 0;
}