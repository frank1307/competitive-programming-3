#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;


void processInstruction(string s,int * position){
	if(s[0]=='L'){
		(*position)--;
	}
	else{
		(*position)++;
	}
}

string sameAsInstruction(string s,vector<string> & vec){
	if(s[0]=='S'){
		int number;	string same;
		istringstream sString(s);
		sString>>same;sString>>same;sString>>number;
		return vec[number-1];
	}
	else{
		return s;
	}
	
}


int main(int argc,char **argv){
	vector<string> instructions;
	int nQuery,nInstru,position;
	string instruu;
	position=0;
	vector<string>::iterator ite;
	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		cin>>nInstru;
		cin.ignore();
		for(int j=0;j<nInstru;j++){
			getline(cin,instruu);
			instructions.push_back(instruu);
		}
		for(ite=instructions.begin();ite!=instructions.end();ite++){
			instruu=*ite;
			*ite=sameAsInstruction(instruu,instructions);
		}
		for(ite=instructions.begin();ite!=instructions.end();ite++){
			processInstruction(*ite,&position);
		}
		cout<<position<<endl;
		position=0;
		instructions.clear();
	}
	return 0;
}
