#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,numberWalls;
	int * walls;
	int hj,lj;
	hj=lj=0;
	cin>>nQuery;

	for(int i=0;i<nQuery;i++){
		cin>>numberWalls;
		walls=new int[numberWalls];
		for(int j=0;j<numberWalls;j++){
			cin>>walls[j];
		}
		for(int j=0;j<=numberWalls-2;j++){
			if(walls[j]<walls[j+1]){
				hj++;
			}
			else if(walls[j]>walls[j+1]){
				lj++;
			} 
		}
		printf("Case %d: %d %d/n",i+1,hj,lj);
		delete []walls;
		lj=hj=0;
	}
	return 0;
}