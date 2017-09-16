#include<iostream>
using namespace std;
//Implement a queue
struct node{
    int val;
    node* next;
};

class queue{
    node* front;
    node* back;
    public:
    void top(){
        if(front!=NULL)
           cout<< front->val<<"\n";
       else
        cout<<"No elements left\n";
    }

    void push_back(int val){
        node *newNode = new node;
        newNode->val=val;
        if(front==NULL){
            front=newNode;
            back=newNode;
        }
        else{
            back->next=newNode;
            back=newNode;
        }
    }

    void pop_front(){
        if(front!=NULL){
            front=front->next;
        }
    }

    int isEmpty(){
        if(front==NULL){
            return 1;
        }
        return 0;
    }

};
int main(){
      
    queue q;
    q.push_back(5); 
    q.push_back(4);
    q.push_back(7);
    q.top();
    q.pop_front();
    q.top(); 
    q.pop_front();
    q.top();
    q.pop_front();
    q.top();
    return 0;
}