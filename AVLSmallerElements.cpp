// Count smaller elements on right side

#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	int num_left;
	node* left;
	node* right;
};

void insert(node* root,int val, int &sum){
	
	if(root==NULL){
		node* newNode=new node;
		newNode->val=val;
		newNode->num_left=0;
		return newNode;
	}
	if(val>root->val)
	{
		sum+=root->num_left+1;
		root->right=insert(root->right, val, sum);
	}
	else
	{
		root->num_left=root->num_left+1;
		root->left=insert(root->left, val, sum);
	}
}
int main(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	// insert from right side
	for(int i=n-1;i>=0;i--){
		int sum=0;
		insert(node* root, v[i], sum);
		cout<<sum<<"\n";
	}
	return 0;
}