#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

pair<int,int> orderedPair(int left,int right){
	if(left==right){
		return make_pair(left,right);
	}
	else if(right>left){
		return make_pair(left,right);
	}
	else{
		return make_pair(right,left);
	}
}

bool checkValidity(string myString,pair<int,int> myPair){
	char temp=myString[myPair.first];
	for(int i=myPair.first;i<=myPair.second;i++){
		if(temp!=myString[i]){
			return false;
		}
	}
	return true;
}

int main(int argc,char ** argv){
	string bits;
	int nQuery;
	int left,right;
	int count=1;
	pair<int,int> myPair;
	while(cin>>bits){
		cout<<"Case "<<count<<":"<<endl;
		cin>>nQuery;
		for(int i=0;i<nQuery;i++){
			cin>>left>>right;
			myPair=orderedPair(left,right);
			bool answer=checkValidity(bits,myPair);
			if(answer){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
		count++;
	}
	return 0;
}