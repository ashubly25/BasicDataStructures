// Find an element in a sorted matrix.
#include<bits/stdc++.h>
using namespace std;
int arr[500][500];
int n,m;
int func(int element,int lowx,int lowy,int highx,int highy){
	if(lowx>=n||lowy>=m||highx<0||highy<0)
		return 0;

	if(lowx>highx||lowy>highy)
		return 0;

	int midx=lowx+(highx-lowx)/2;
	int midy=lowy+(highy-lowy)/2;

	if(arr[midx][midy]==element)
		return 1;

	if(arr[midx][midy]<element){
		return func(element,midx,midy+1,highx,highy) || func(element,midx+1,lowy,highx,midy);
	}
	else
	if(arr[midx][midy]>element){
		return func(element,lowx,lowy,midx,midy-1) || func(element,lowx,midy,midx-1,highy);
	}
	return 0;

}
int main(){

	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	}
	int element;cin>>element;

	if(func(element,0,0,n-1,m-1))
		cout<<"Found\n";
	return 0;
}