//https://www.careercup.com/question?id=5678803027230720
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int len=s.length();
  int dp[len];
  dp[0]=1;
  dp[1]=2;
  for(int i=2;i<len;i++){
    dp[i]=dp[i-1]+dp[i-2];
  }
  cout<<dp[len-1];
  return 0;
}
