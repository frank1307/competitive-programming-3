#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string positionX(string now,string command){
	
	if(now[0]=='+'){
		if(command=="+y"){return "+y";}
		else if(command=="-y"){return "-y";}
		else if(command=="+z"){return "+z";}
		else{return "-z";}
	}
	else{
		if(command=="+y"){return "-y";}
		else if(command=="-y"){return "+y";}
		else if(command=="+z"){return "-z";}
		else{return "+z";}
	}
}

string positionY(string now,string command){
	if(now[0]=='+'){
		if(command=="+y"){return "-x";}
		else if(command=="-y"){return "+x";}
		else { return "+y";}
	}
	else{
		if(command=="+y"){return "+x";}
		else if(command=="-y"){return "-x";}
		else {return "-y";}	
	}
}


string positionZ(string now,string command){
	if(now[0]=='+'){
		if(command=="+z" ){return "-x";}
		else if(command=="-z"){return "+x";}
		else { return "+z";}
	}
	else{
		if(command=="+z"){return "+x";}
		else if(command=="-z"){return "-x";}
		else {return "-z";}	
	}
}



string entryOut(string now,string command){
	if(command=="No"){
		return now;
	}
	else{
		if(now[1]=='x') return positionX(now,command);
		else if(now[1]=='y') return positionY(now,command);
		else return positionZ(now,command);
	}
}


int main(int argc,char ** argv){
	int nQuery;
	string now,command;
	cin>>nQuery;
	while(nQuery!=0){
		now="+x";
		for(int i=0;i<nQuery-1;i++){
			cin>>command;
			now=entryOut(now,command);
		}
		cout<<now<<endl;
		cin>>nQuery;
	}
	return 0;
}