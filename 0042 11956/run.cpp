#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


void changeMemory(int * memory , string instructions){
	int position=0;
	string instruction;
	for(int i=0 ; i<instructions.length() ; i++){
		instruction=instructions[i];
		if(instruction==">"){
			position++;
			position=position%100;
		}
		else if(instruction=="<"){
			position--;
			if(position<0){
				position=100+position;  //position is negative
			}
		}
		else if(instruction=="+"){
			memory[position]++;
			memory[position]%=256;
		}
		else if(instruction=="-"){
			memory[position]--;
			if(memory[position]<0){
				memory[position]=256+memory[position];
			}
		}
	}
}

void printMemory(int * memory){
	for(int i=0;i<99;i++){
		printf("%02X ",memory[i]);
	}
	printf("%02X\n",memory[99]);
}

int main(int argc,char ** argv){
	int vectora[100];
	string instructions;
	int nQuery;
	cin>>nQuery;
	cin.ignore();
	for(int i=0;i<nQuery;i++){
		for(int i=0;i<100;i++){
			vectora[i]=0;
		}
		getline(cin,instructions);
		changeMemory(vectora,instructions);
		cout<<"Case "<<i+1<<": ";
		printMemory(vectora);
	}
	return 0;
}