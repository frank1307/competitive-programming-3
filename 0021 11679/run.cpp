#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int main(int argc,char ** argv){
	int B,N;
	int D,C,howMuch;
	int * account;
	bool situation=false;
	cin>>B>>N;
	while(B!=0 && N!=0){
		account= new int[B];
		for(int i=0;i<B;i++){
			cin>>account[i];
		}
		for(int i=0;i<N;i++){
			cin>>D>>C>>howMuch;
			account[D-1]-=howMuch;
			account[C-1]+=howMuch;
		}
		for(int i=0;i<B;i++){
			if(account[i]<0){
				situation=true;
			}
		}
		if(situation==true){
			cout<<"N"<<endl;
		}
		else{
			cout<<"S"<<endl;
		}
		situation=false;
		delete []account;
		cin>>B>>N;
	} 
	return 0;
}