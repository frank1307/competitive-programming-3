#include <iostream>
#include <tuple>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(int argc,char ** argv){
	int n,m,temp;
	map<int,bool> myMap;
	while(true){ 
		myMap.clear();
		cin>>n;
		if(n==0){
			return 0;
		}
		cin>>m;
		for(int i=0;i<n;i++){
			cin>>temp;
			myMap[temp]=true;
		}
		bool control=true;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			for(int j=0;j<a;j++){
				cin>>temp;
				if(myMap[temp]){
					b--;
				}
			}
			if(b>0){
				control=false;
			}
		}
		if(control){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}

	}
	return 0;
}