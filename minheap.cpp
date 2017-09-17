#include<iostream>
using namespace std;
#define MAX 10000
int ceil(int val1, int val2){
	
	if((double)val1/(double)val2==(double)(val1/val2))
		return (int)(val1/val2);
	return (int)(val1/val2)+1;
}
int swap(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}
void print(int arr[], int size){
	for(int i=0;i<size;i++)
		cout<<arr[i]<<"  ";
	cout<<"\n";
}
class priority_queue{
	int arr[MAX];
	int size;
	void heapify(int arr[], int size){
		
		int parent=ceil((size-1),2);
		
		int child=size;
		while(parent>0){
			//check if parent is greater than inserted val
			if(arr[parent-1]>arr[child-1]){
				swap(arr[parent-1], arr[child-1]);
			}
			child=parent;
			parent=ceil((parent-1),2);
		}
	}

	void heapify_pop(int arr[], int size, int index){
		//check smallest amongst all the three i.e parent, left and right child and 
		//then replace with the root/parent and move in that direction

		while(1){

		if(2*index+1>=size||index==-1)
			break;

		int smallest=arr[index];
		int direction=-1;
		int f=0, g=0;

		if(2*index+1<size){
			// left child exists
			if(arr[index]>arr[2*index+1]){
				g=1;
				smallest=arr[2*index+1];
				direction=2*index+1;
			}

			if(2*index+2<size){
			// right child exists
			if(smallest>arr[2*index+2]){
				f=1;
				smallest=arr[2*index+2];
				direction=2*index+2;
				swap(arr[index], arr[2*index+2]);
			}
			}

			if(f==0&&g==1)
			swap(arr[index], arr[2*index+1]);
			index=direction;

		}
		}
	}

public:
	priority_queue(){
		size=0;
	}

	void push(int val){
		//heapify 
		arr[size]=val;
		size++;
		heapify(arr,size);
	}

	void pop(){
		//replace 0th index with size-1 and initiate heapify
		//decrease size of heap
		arr[0]=arr[size-1];
		size--;
		heapify_pop(arr, size, 0);
	}

	void top(){
		if(size>0)
		cout<<"\nSIZE="<<size<<"   "<<arr[0]<<"\n";
	    else
	    cout<<"Heap is empty\n";
	}
};
int main(){

	priority_queue q;
	q.top();
	q.push(4);
	q.push(2);
	q.push(0);
	q.push(5);
	q.pop();
	q.top();
	q.pop();
	q.top();
	return 0;
}