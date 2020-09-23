#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool checkOrdering(int * lumberGuys){
	bool nondecreasing=false;
	bool nonincreasing=false;
	for(int i=0;i<=8;i++){
		if(lumberGuys[i]==lumberGuys[i+1]){
			continue;
		}
		if(lumberGuys[i]>lumberGuys[i+1]){
			if(nonincreasing==true){
				return false;
			}
			else{
				nondecreasing=true;
			}
		}
		else{
			if(nondecreasing==true){
				return false;
			}
			else{
				nonincreasing=true;
			}

		}
	}
	return true;
}

int main(int argc,char ** argv){
	cout<<"Lumberjacks:"<<endl;
	int nQuery;
	int auxInt;
	int lumberBeardHeight[10];
	bool answer;
	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		for(int j=0;j<10;j++){
			cin>>lumberBeardHeight[j];
		}
		answer=checkOrdering(lumberBeardHeight);
		if(answer){
			cout<<"Ordered"<<endl;
		}
		else{
			cout<<"Unordered"<<endl;
		}
	}
	return 0;
}