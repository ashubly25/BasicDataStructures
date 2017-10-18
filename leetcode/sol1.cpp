#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
string s;cin>>s;
//longest substring with unique characters
int i=0,j=0,len=0;
map<char,int> mp;
while(j<s.length()){
  if(!mp.empty()&&mp.find(s[j])!=mp.end()){
    mp.erase(s[i]);
    i++;
  }
  else
  {
    mp[s[j]]=1;
    j++;
    len=max(len,j-i);
  }
}
cout<<len<<"\n";
}
return 0;
}
