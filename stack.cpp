#include<iostream>
using namespace std;
struct node{
	int val;
	node *next;
};
class stack{
	node* top;
public:
	void push(int val){
		node* newNode=new node;
		newNode->val=val;
		if(top==NULL){
			top=newNode;
		}
		else{
			newNode->next=top;
			top=newNode;
		}
	}
	void pop(){
		if(top==NULL){
			cout<<"Stack is empty\n";
		}
		else{
			top=top->next;
		}
	}
	void topE(){
		if(top==NULL){
			cout<<"Stack is empty\n";
		}
		else{
			cout<<top->val<<"\n";
		}
	}
};
int main(){

	stack s;
	s.pop();
	s.push(4);
	s.push(5);
	s.topE();
	return 0;
}