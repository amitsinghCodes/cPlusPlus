//length pf the longest string woitout repeast;
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int longstring(string s){
  vector<int>freq(256,0);//ascii 256        or       map<char , int> freq;
  int best = 0; int left = 0; int beststart = 0, bestend = 0;
  for(int i =0;i < s.size(); i++){
  freq[s[i]]++;
  //cout<<freq[s[i]];
  while(freq[s[i]] > 1){
      freq[s[left]]--;
      left++;
  }
  if(i - left + 1 > bestend){
      bestend = i - left + 1;
      beststart =  left;
  }
  
      best = max(best, i - left + 1);
  }
  cout<< s.substr(beststart, bestend);
  cout<<best;
  return best;
}

int main(){
string s = "abcabcdeaa";
int x = longstring(s);
//cout<<x;
return 0;
}