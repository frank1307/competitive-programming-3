#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

class House{
	
public:
	vector<pair<int,bool>> homeAppliances;
	int n,maxPower,maxFuse,actualPower;
	
	House(int * cosumption,int n,int maxFuse){
		this->n=n;
		this->maxFuse=maxFuse;
		maxPower=0;
		for(int i=0;i<n;i++){
			(homeAppliances).push_back(make_pair(cosumption[i],false));
		}
	}
	
	~House(){
		homeAppliances.clear();
	}

	int calculateFuse(){
		int sum=0;
		vector<pair<int,bool>>::iterator ite; 

		for(ite=homeAppliances.begin();ite!=homeAppliances.end();ite++){
			if(ite->second){
				sum+=ite->first;
			}
		}
		return sum;

	}

	bool addEquipment(int number){
		pair<int,bool> & temp=homeAppliances[number];
		if(temp.second==true){
			temp.second=false;
			actualPower=calculateFuse();
			return false;
		}
		else{
			temp.second=true;
			actualPower=calculateFuse();
			
			if(actualPower>maxPower){
				maxPower=actualPower;
			}
			if(actualPower > maxFuse){
				return true;
			}
			return false;
		}
	}
};

int main(int argc,char ** argv){
	int n,m,c,temp,j;
	cin>>n>>m>>c;
	j=1;
	bool blownFuse;
	int * fuseArray;
	while(n!=0 && m!=0 && c!=0){
		blownFuse=false;
		fuseArray=new int[n];
		for(int i=0;i<n;i++){
			cin>>fuseArray[i];
		}
		House * house=new House(fuseArray,n,c);
		for(int i=0;i<m;i++){
			cin>>temp;	
			if( house->addEquipment(temp-1) ){
				blownFuse=true;
			}
		}

		cout<<"Sequence "<<j<<endl;
		if(blownFuse){
			cout<<"Fuse was blown."<<endl;
		}
		else{
			cout<<"Fuse was not blown."<<endl;
			cout<<"Maximal power consumption was "<< house->maxPower<<" amperes."<<endl;
		}

		cin>>n>>m>>c;
		delete []fuseArray;
		
		cout<<endl;

		j++;
	}
	return 0;
}