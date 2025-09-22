#include<iostream>

using namespace std;

char* remove_space(char* ptr){
int read = 0 , write = 0; bool prevSpace = false;

while(ptr[read] == ' ') ++read;

while(ptr[read] != '\0'){
char c = ptr[read++];

if(c == ' '){
if(!prevSpace){
ptr[write++] = ' ';
prevSpace = true;
}
}
else if(c == '!' ||c == '?' ||c == '.' ||c == ',')
{--write; ptr[write++] = c;}
else{
ptr[write++] = c;
prevSpace = false;
}
}
if(write > 0 && ptr[write - 1] == ' ') --write;
ptr[write] = '\0';
return ptr;
}


int main(){
char ch[] = " abc nbc   cc ccc an     abc  .   ";

remove_space(ch);
cout<<ch;
return 0;
}