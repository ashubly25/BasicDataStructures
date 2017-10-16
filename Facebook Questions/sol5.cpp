//https://www.careercup.com/question?id=6208755887767552
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
  cin>>v[i];
  vector<int> visited(n,0);
  int flag=0;
  int i=0;
  int count=0;
  while(count<n){
    if(((i+v[i])%n)!=i&&visited[(i+v[i])%n]==1){
      flag=1;
      cout<<"Loop detected at "<<i;
      break;
    }
    visited[i]=1;
    i=(i+v[i])%n;
    count++;
  }
  if(flag==0)
  cout<<"No loop detected\n";
  return 0;
}
