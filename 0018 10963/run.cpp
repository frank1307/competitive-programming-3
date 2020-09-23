#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int findMinimumGap(int * gap,int length){
	int minimum=10000;
	for(int i=0;i<length;i++){
		if(gap[i]<minimum){
			minimum=gap[i];
		}
	}
	return minimum;
}

void swallowGround(int * gap,int length,int minimumGap){
	for(int i=0;i<length;i++){
		gap[i]=gap[i]-minimumGap;
	}
}

bool checkHoles(int * gap,int length){
	for(int i=0;i<length;i++){
		if(gap[i]>0.05){
			return true;
		}
	}
	return false;
}

int main(int argc,char ** argv){
	int nQuery,nGaps,y1,y2,minimumGap;
	int * arrayGaps;

	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		cin>>nGaps;
		arrayGaps= new int[nGaps];
		for(int j=0;j<nGaps;j++){
			cin>>y1>>y2;
			arrayGaps[j]=y1-y2;
		}
		minimumGap=findMinimumGap(arrayGaps,nGaps);
		swallowGround(arrayGaps,nGaps,minimumGap);
		if(checkHoles(arrayGaps,nGaps)){
			cout<<"no"<<endl;
		}
		else{
			cout<<"yes"<<endl;
		}
		delete[] arrayGaps;
		if(i!=(nQuery-1)){
			cout<<endl;
		}

	}
	return 0;
}