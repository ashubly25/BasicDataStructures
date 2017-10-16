//https://www.careercup.com/question?id=5712224583680000
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
  node* root=newN(2);
  root->left=newN(5);
  root->right=newN(8);
  root->right->left=newN(10);
  root->right->right=newN(1);
  return root;
}
int h(node* root){
  if(root==NULL)
  return 0;
  return 1+max(h(root->left),h(root->right));
}
void printNodes(node* root, int level){
  if(root==NULL)
  return;
  if(level==1)
  {
    cout<<root->val<<" ";
    return;
  }
  printNodes(root->left,level-1);
  printNodes(root->right,level-1);
}
int main(){
  node* root=constructTree();
  //height of tree
  int height=h(root);
  for(int i=height;i>0;i--){
    //height--> i
    //print nodes at he height i
    printNodes(root,i);
  }
  return 0;
}
