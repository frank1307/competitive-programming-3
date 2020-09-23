#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int mileCosta(int * calls,int length){
	int cost=0;
	for(int i=0;i<length;i++){
		cost=cost+ ((calls[i]/30)+1)*10;
	}
	return cost;
}

int juiceCosta(int * calls,int length){
	int cost=0;
	for(int i=0;i<length;i++){
		cost=cost+ ((calls[i]/60)+1)*15;
	}
	return cost;
}

int main(int argc,char ** argv){
	int nQuery;
	int numberCases;
	int juiceCost,mileCost;
	int * calls;
	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		cin>>numberCases;
		calls=new int[numberCases];
		for(int j=0;j<numberCases;j++){
			cin>>calls[j];
			
		}
		juiceCost=juiceCosta(calls,numberCases);
		mileCost=mileCosta(calls,numberCases);
		if(juiceCost<mileCost){
			cout<<"Case "<<i+1<<": Juice "<<juiceCost<<endl;
		}
		else if(juiceCost>mileCost){
			cout<<"Case "<<i+1<<": Mile "<<mileCost<<endl;
		}
		else{
			cout<<"Case "<<i+1<<": Mile Juice "<<juiceCost<<endl;
		}
		delete [] calls;
	}
	return 0;
}