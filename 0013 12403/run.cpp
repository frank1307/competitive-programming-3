#include<iostream>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,auxa,amount;
	amount=0;
	string aux;
	cin>>nQuery
	for(int i=0;i<nQuery;i++){
		cin>>aux;
		if(aux=="report"){
			cout<<amount<<endl;
		}
		else{
			cout<<auxa<<endl;
			amount=amount+auxa;
		}
	}
	return 0;
}