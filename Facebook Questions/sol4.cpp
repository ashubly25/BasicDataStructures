//https://www.careercup.com/question?id=5695490988441600
#include<bits/stdc++.h>
using namespace std;
struct node{
  int val;
  node* left;
  node* right;
};
node* newN(int val){
  node *newNode= new node;
  newNode->val=val;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}
node* constructTree(){
  node* root=newN(10);
  root->left=newN(5);
  root->right=newN(15);
  root->right->left=root->left;
  root->right->right=newN(20);
  return root;
}
void checkCulprit(node* root, int min, int max){
  if(root==NULL)
  return;
  if(root->val<min||root->val>max){
    cout<<root->val<<" ";
    return;
  }
  checkCulprit(root->left, min, root->val-1);
  checkCulprit(root->right, root->val+1, max);
}
int main(){
  node* root=constructTree();
  //check which node has two parents
  int min=INT_MIN;
  int max=INT_MAX;
  checkCulprit(root,min,max);
  return 0;
}
