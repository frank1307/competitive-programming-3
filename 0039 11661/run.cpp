#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc,char ** argv){
	int nQuery;
	int minDistance;
	int distance;
	char actual,past;
	string road;
	cin>>nQuery;
	while(nQuery!=0){
		cin.ignore();
		minDistance=100000000;
		distance=0;
		past='.';
		getline(cin,road);
		for(int i=0;i<road.length();i++){
			actual=road[i];
			if(actual=='Z') {
				minDistance=0;
				break;
			}
			if(actual=='D'){
				if(past=='D'){
					distance=0;
				}
				else if(past=='.'){
					distance=0;
					past='D';
				}
				else{
					distance++;
					past='D';
					if(distance<minDistance){
						minDistance=distance;
					}
					distance=0;
				}
			}
			else if(actual=='R'){
				if(past=='R'){
					distance=0;
				}
				else if(past=='.'){
					distance=0;
					past='R';
				}
				else{
					distance++;
					past='R';
					if(distance<minDistance){
						minDistance=distance;
					}
					distance=0;
				}
			}
			else{
				if(past=='D' || past=='R'){
					distance++;
				}
			}
		}
		cout<<minDistance<<endl;
		cin>>nQuery;
	}
	return 0;
}