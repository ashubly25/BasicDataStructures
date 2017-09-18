#include<bits/stdc++.h>
using namespace std;

void convert_to_bin(int num){
	int rem;
    if (num <= 1){
      cout << num;  
      return;
    }
    rem = num % 2;
    convert_to_bin(num / 2);
    cout << rem;
}

void print(vector<int> v){
	for(int i=0;i<v.size();i++){
		convert_to_bin(v[i]);
		cout<<"    ";
	}
	cout<<"\n";
}

int main(){
	int n1,n2;
	cin>>n1>>n2;
	vector<int> v1,v2;
	for(int i=0;i<n1;i++){
		string s;
		cin>>s;
		int b=0;
		for(int i=0;i<s.length();i++){
			b=b|(1<<(s[i]-65));
		}
		v1.push_back(b);
	}
	for(int i=0;i<n2;i++){
		string s;
		cin>>s;
		int b=0;
		for(int i=0;i<s.length();i++){
			b=b|(1<<(s[i]-65));
		}
		v2.push_back(b);
	}

	// print(v1);
	// print(v2);

	int count=0;
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			convert_to_bin(v1[i]|v2[j]);
			cout<<"\n";
			if(v1[i]|v2[j]==(1<<26-1))
				count++;
		}
	}

	cout<<count<<"\n";
	return 0;
}