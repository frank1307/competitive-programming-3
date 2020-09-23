#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

struct Proposal{
	string name;
	float value;
	int position;
	int manyChecks;
};

string findMark(vector<Proposal> &proposal){
	float minimumAmount=std::numeric_limits<float>::max();
	vector<string> proposalMark;
	vector<Proposal>::iterator ite;
	
	for(ite=proposal.begin();ite!=proposal.end();ite++){
		if(ite->value<minimumAmount){
			minimumAmount=ite->value;
			proposalMark.clear();
			proposalMark.push_back(ite->name);
		}
		else{
			if(ite->value==minimumAmount){
				proposalMark.push_back(ite->name);
			}
		}
	}
	return proposalMark[0];
}


int main(int argc,char ** argv){
	int nQuery,nProposals; int count=1;int manyChecks=0;
	string temp;
	cin>>nQuery>>nProposals;
	Proposal proposal;
	vector<Proposal> myPVector; 
	cin.ignore();

	
	while(true){
		manyChecks=0;
		for(int i=0;i<nQuery;i++){
			getline(cin,temp);
		}
		for(int i=0;i<nProposals;i++){
			getline(cin,proposal.name);
			proposal.position=i;
			cin>>proposal.value>>proposal.manyChecks;
			cin.ignore();

			for(int j=0;j<proposal.manyChecks;j++){
				getline(cin,temp);
			}

			if(proposal.manyChecks>manyChecks){
				manyChecks=proposal.manyChecks;
				myPVector.clear();
				myPVector.push_back(proposal);
			}
			else{
				if(proposal.manyChecks==manyChecks){
					myPVector.push_back(proposal);
				}
				else{
				}
			}
		}

		temp=findMark(myPVector);
		cout<<"RFP #"<<count<<endl;
		cout<<temp<<endl;
		count++;

		myPVector.clear();
		cin>>nQuery>>nProposals;
		if(nQuery==0){
			break;
		}
		else{
			cout<<endl;
		}
		cin.ignore();
	}
	return 0;
}