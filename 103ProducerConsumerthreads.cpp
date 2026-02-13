#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unordered_set>

using namespace std;

vector<int> buffer;
mutex mtx;
condition_variable cv;
bool done = false;

// ---------------- PRODUCER ----------------
void producer(const vector<int>& input) {
    for (int x : input) {
        {
            unique_lock<mutex> lock(mtx);
            buffer.push_back(x);
            cout << "Produced: " << x << endl;
        }
        cv.notify_one();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    // signal finished
    {
        unique_lock<mutex> lock(mtx);
        done = true;
    }
    cv.notify_one();
}

// ---------------- CONSUMER ----------------
void consumer() {
    vector<int> consumed;

    while (true) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [] {
            return !buffer.empty() || done;
        });

        while (!buffer.empty()) {
            int val = buffer.back();
            buffer.pop_back();
            consumed.push_back(val);
            cout << "Consumed: " << val << endl;
        }

        if (done) break;
    }

    // ----- REMOVE DUPLICATES -----
    unordered_set<int> seen;
    vector<int> unique;

    for (int x : consumed) {
        if (seen.insert(x).second) {
            /*
            For set / unordered_set:
insert(value)
returns:
pair<iterator, bool>
• .first → iterator to element
• .second → true if insertion succeeded
• .second → false if element already existed
So:
seen.insert(x).second
means:
👉 “Was x NOT already present?”
If true:
first time seeing x
insert into unique list
If false:
duplicate → skip
            */
            unique.push_back(x);
        }
    }

    cout << "\nAfter removing duplicates:\n";
    for (int x : unique)
        cout << x << " ";
    cout << endl;
}

// ---------------- MAIN ----------------
int main() {

    vector<int> input = {1, 2, 3, 4, 2, 5, 3, 6};

    thread t1(producer, cref(input));
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
