//https://www.careercup.com/question?id=5768044260360192
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int target;cin>>target;
  vector<int> v(n);
  for(int i=0;i<n;i++)
  cin>>v[i];

  int ans=0;
  int prod=v[0];
  deque<int> q;
  q.push_back(v[0]);
  //sliding window approach
  for(int i=1;i<n;i++){
      if(v[i]<=target){
        //ans+=1;
        //cout<<i<<"  :  "<<ans<<"\n";
        if(prod!=1&&prod*v[i]<=target){
          q.push_back(v[i]);
          prod*=v[i];
          ans++;
        //  cout<<i<<"  :  "<<ans<<"\n";
        }
        else{
          while(!q.empty()&&prod*v[i]>target){
            ans++;
            int val=q.front();
            prod=prod/val;
            q.pop_front();
          }
          if(!q.empty()&&prod*v[i]<=target){
            ans++;
          //  cout<<i<<"  :  "<<ans<<"\n";
          }
          q.push_back(v[i]);
          prod*=v[i];
        }
      }
      else{
        prod=1;
        q.clear();
      }
  }
  cout<<ans<<"\n";
  return 0;
}
