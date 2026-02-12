#include <iostream>
#include <vector>
#include <string>
using namespace std;


class BrowserHistory {
    vector<string> site;
    int current;
    int last;
public:
    BrowserHistory(string homepage) {
        site.push_back(homepage);
        current = 0;
        last = 0;
    }
    
    void visit(string url) {
        current++;
        if(current < (int)site.size()){
            site[current] = url;
        }
        else{
            site.push_back(url);
        }
        last = current;
    }
    
    string back(int steps) {
        current = max(0, current - steps);
        return site[current];
    }
    
    string forward(int steps) {
        current = min(last, current + steps);
        return site[current];
    }
};

int main() {

    BrowserHistory browser("leetcode.com");

    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << browser.back(1) << endl;     // facebook.com
    cout << browser.back(1) << endl;     // google.com
    cout << browser.forward(1) << endl;  // facebook.com

    browser.visit("linkedin.com");

    cout << browser.forward(2) << endl;  // linkedin.com
    cout << browser.back(2) << endl;     // google.com
    cout << browser.back(7) << endl;     // leetcode.com

    return 0;
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */