//Partition of a set into K subsets with equal sum
//Fails for 4,15,1,1,1,1,3,11,1,10 and k=3
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int k;cin>>k;
  vector<int> v(n);
  int sum=0;
  for(int i=0;i<n;i++){
  cin>>v[i];
  sum+=v[i];
  }
  int expectedSum=sum/k;
  //cout<<"Expected Sum  "<<expectedSum<<"\n";
  sort(v.begin(),v.end());
  int i=0,j=n-1;
  int tempk=0;
  int tempSum=0;
  while(i<j){
    if(v[i]==expectedSum){
    i++;
    tempk++;
    }
    else
    if(v[j]==expectedSum){
    j--;
    tempk++;
    }
    else{
      if(tempSum+v[i]+v[j]==expectedSum){
        i++;j--;
        tempk++;
        tempSum=0;
      }
      else
      if(tempSum+v[i]+v[j]<expectedSum){
        tempSum+=v[i];
        i++;
      }
      else
      if(tempSum+v[i]+v[j]>expectedSum){
        tempSum+=v[j];
        j--;
      }
    }
  }
  if(tempk==k&&i>j)
  cout<<"YES\n";
  else
  cout<<"NO\n";
  return 0;
}
