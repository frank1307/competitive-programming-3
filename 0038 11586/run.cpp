#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
pair<int,int> processEntry(string word){
	if(word[0]=='M' && word[1]=='M'){
		return make_pair(2,0);
	}
	else if(word[0]=='F' && word[1]=='F'){
		return make_pair(0,2);
	}
	else{
		return make_pair(1,1);
	}
}


int main(int argc,char ** argv){
	int nQuery;
	int nMale,nFemale;
	string temp;
	cin>>nQuery;
	cin.ignore();
	while(nQuery--){
		nMale=nFemale=0;
		getline(cin,temp);
		for(int i=0;i<temp.length();i++){
			if(temp[i]=='M'){
				nMale++;
			}
			else if(temp[i]=='F'){
				nFemale++;
			}
		}
		if(nMale==nFemale && nMale!=1){
			cout<<"LOOP"<<endl;
		}
		else{
			cout<<"NO LOOP"<<endl;
		}

	}
	return 0;
}