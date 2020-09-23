#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<map>

using namespace std;

int main(int argc,char ** argv){
	map<string,int> myMap;
	vector<string> myVector;
	int nQuery;
	int budget,nPeople;
	string name;

	cin>>nQuery;
	while(true){
		for(int i=0;i<nQuery;i++){
			cin>>name;
			myVector.push_back(name);
			myMap[name]=0;
		}
		for(int i=0;i<nQuery;i++){
			cin>>name>>budget;
			cin>>nPeople;
			if(nPeople>0){
				myMap[name]=myMap[name]-budget+(budget-(budget/nPeople)*nPeople);
				for(int j=0;j<nPeople;j++){
					cin>>name;
					myMap[name]=myMap[name]+(budget/nPeople);
				}		
			}
			else{
				for(int j=0;j<nPeople;j++){
					cin>>name;
				}
			}

		}
		vector<string>::iterator ite;
		for(ite=myVector.begin();ite!=myVector.end();ite++){
			cout<<*ite<<" "<<myMap[*ite]<<endl;
		}
		if(cin>>nQuery){
			cout<<endl;
			myMap.clear();
			myVector.clear();
		}
		else{
			break;
		}
	}
	return 0;
}