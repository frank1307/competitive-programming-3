#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,nCreatures,maxSpeed;
	maxSpeed=0;
	int auxSpeed;
	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		cin>>nCreatures;
		for(int j=0;j<nCreatures;j++){
			cin>>auxSpeed;
			if(auxSpeed>maxSpeed){
				maxSpeed=auxSpeed;
			}
		}
		printf("Case %d: %d /n",i+1,maxSpeed);
		maxSpeed=0;
	}
	return 0;
}