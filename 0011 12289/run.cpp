#include <iostream>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,aux;
	string word;
	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		cin>>word;
		aux=word.length();
		if(aux==3){

			if((word[0]=='o' && word[1]=='n') || (word[0]=='o' && word[2]=='e') || (word[1]=='n' && word[2]=='e')){
				cout<<"1"<<endl;
			}
			else{
				cout<<"2"<<endl;
			}
		}
		else{
			cout<<"3"<<endl;
		}
	}
	return 0;
}