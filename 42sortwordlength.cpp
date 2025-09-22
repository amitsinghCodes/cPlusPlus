#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void swap(string &a, string &b){
    string temp = a;
    a = b;
    b = temp;
}

int main(){
    string  str;
    getline(cin,str);
    
    string wordList[1000];
    string currentWord = "";
    int wordCount = 0;

    for(char ch : str){
        if(ch != ' '){
            currentWord = currentWord + ch;
        }
        else {
             if(!currentWord.empty()){
             wordList[wordCount++] = currentWord;
             currentWord = "";
             }
        }

    }

    if(!currentWord.empty()){
        wordList[wordCount++] =  currentWord;
    }


    for(int i = 0;i<= wordCount - 1; i++){
        for(int j = 0; j<= wordCount - i - 1; j++){
            if(wordList[j].length() > wordList[j + 1].length()){
                swap(wordList[j],wordList[j+1]);
            }
        }
    }

    for(int i = 0;i<= wordCount ; i++){
        cout<<wordList[i]<<" ";
    }

    return 0;
}