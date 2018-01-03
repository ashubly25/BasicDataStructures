//Trie Implementation
#include<bits/stdc++.h>
using namespace std;
struct node{
	node* children[26];
	bool last;
};
node* getNode(){
	node* n=new node;
	n->last=false;
	for(int i=0;i<26;i++)
		n->children[i]=NULL;
	return n;
}
void insert(node* root, string key){
	int length=key.length();
	node* temp=root;
	for(int i=0;i<length;i++){
		if(temp->children[key[i]-'a']==NULL)
			temp->children[key[i]-'a']=getNode();
		temp=temp->children[key[i]-'a'];
	}
	temp->last=true;
}
bool find(node* root, string key, int index){
	if(index==key.length()){
		if(root->last)
		return true;
		return false;
	}
	if(root->children[key[index]-'a']==NULL)
		return false;
	return find(root->children[key[index]-'a'], key, index+1);
}
int main(){
	int n;cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	node *root=getNode();
	for(int i=0;i<n;i++)
		insert(root,v[i]);

	cout<<"Enter a string\n";
	string ss;cin>>ss;

	if(find(root,ss,0))
		cout<<"Found\n";

	return 0;
}