#include <iostream>
#include <queue>
using namespace std;

class qutstack{
queue<int> q1, q2;

public: 

void push(int x){
q2.push(x);               // push into q2
while(!q1.empty()){       //reversing order
q2.push(q1.front());
q1.pop();
}
swap(q1, q2);
}

void pop(){
q1.pop();
}

int size(){
return q1.size();
}

bool empty(){
return q1.empty();
}

friend ostream& operator<<(ostream& out, qutstack& obj){
    queue<int>q = obj.q1;
    while(!q.empty()){
        out<<q.front()<< " ";
        q.pop();
    }
    return out;
}
};

int main(){
qutstack s1;
s1.push(10); s1.push(20); s1.push(30);
cout<<s1;
s1.pop();
cout<<s1;
return 0;
}