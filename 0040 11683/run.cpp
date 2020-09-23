#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

int calculateHowManyTimes(bool * myVector,int length){
	bool control=false;
	int count=0;
	for(int i=0;i<length;i++){
		if(myVector[i]==true){
			if(control==false){
				count++;
				control=true;
			}
		}
		else{
			control=false;
		}
	}
	return count;
}


int main(int argc,char ** argv){
	int height,length,sum,before,after;
	cin>>height>>length;
	while(height!=0){
		sum=0;
		before=height;
		for(int i=0;i<length;i++){
			cin>>after;
			if(after>before){
				sum+=after-before;
			}
			before=after;
		}
		if(height!=after){
			sum+=height-after;
		}
		cout<<sum<<endl;
		cin>>height>>length;
	}

	return 0;
}