#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,relevance,maxRelevance;
	cin>>nQuery;
	vector<string> urls;
	vector<string>::iterator ite;
	string newUrl;
	for(int i=0;i<nQuery;i++){
		maxRelevance=0;
		for(int j=0;j<10;j++){
			cin>>newUrl>>relevance;
			if(relevance==maxRelevance){
				urls.push_back(newUrl);
			}
			else if(relevance>maxRelevance){
				urls.clear();
				urls.push_back(newUrl);
				maxRelevance=relevance;
			}
		}
		cout<<"Case #"<<i+1<<":"<<endl;
		for(ite=urls.begin();ite!=urls.end();ite++){
			cout<<*ite<<endl;
		}
		urls.clear();
	}
	return 0;
}