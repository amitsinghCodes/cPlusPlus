#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return max(event1[0], event2[0]) <= min(event1[1], event2[1]);
    }
};

int main() {
    Solution obj;
    vector<string> event1 = {"01:15", "02:00"};
    vector<string> event2 = {"02:00", "03:00"};

    cout << (obj.haveConflict(event1, event2) ? "true" : "false");
    return 0;
}

/*
 int toMinutes(string t){
        int hour = stoi(t.substr(0,2));
        int min  = stoi(t.substr(3,2));
        return hour*60 + min;
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        int s1 = toMinutes(event1[0]);
        int e1 = toMinutes(event1[1]);

        int s2 = toMinutes(event2[0]);
        int e2 = toMinutes(event2[1]);

        return max(s1,s2) <= min(e1,e2);
    }
*/