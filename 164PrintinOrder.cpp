#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int turn;

public:
    Foo() {
        turn = 1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        printFirst();
        turn = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return turn == 2; });
        printSecond();
        turn = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return turn == 3; });
        printThird();
    }
};

int main() {
    Foo foo;

    // Lambdas for printing
    auto printFirst = []() { cout << "first"; };
    auto printSecond = []() { cout << "second"; };
    auto printThird = []() { cout << "third"; };

    // Create threads in random order
    thread t3(&Foo::third, &foo, printThird);
    thread t1(&Foo::first, &foo, printFirst);
    thread t2(&Foo::second, &foo, printSecond);

    // Join threads
    t1.join();
    t2.join();
    t3.join();

    return 0;
}