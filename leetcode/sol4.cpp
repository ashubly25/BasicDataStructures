//Implement maximum xor between two elements
#include<bits/stdc++.h>
using namespace std;
#define INT_SIZE 32
struct node
{
	int val;
	node* children[2];
};
int min_xor(node* root,int key){
	
	node* temp=root;
	for(int i=INT_SIZE-1;i>=0;i--){
		bool index=key&(1<<i);

		if(temp->children[index]!=NULL)
			temp=temp->children[index];
		else
		if(temp->children[1-index]!=NULL)
			temp=temp->children[1-index];
	}
	return key^(temp->val);
}
node* getNode(){
	node* n=new node;
	n->val=0;
	n->children[0]=NULL;
	n->children[1]=NULL;
	return n;
}
void insert(node* root,int key){

	node* temp=root;
	for(int i=INT_SIZE-1;i>=0;i--){
		bool index=key&(1<<i);
		//cout<<index<<"\n";
		if(temp->children[index]==NULL)
			temp->children[index]=getNode();
		temp=temp->children[index];
	}
	temp->val=key;
}
int main(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	node* root=getNode();
	insert(root,arr[0]);

	int ans=INT_MAX;
	for(int i=1;i<n;i++){
		ans=min(ans,min_xor(root,arr[i]));
		insert(root,arr[i]);
	}

	cout<<ans;
	return 0;
} 