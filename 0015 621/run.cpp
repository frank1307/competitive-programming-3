#include <iostream>

using namespace std;

int main(int argc,char **argv){
	int nQuery,lengtha;
	string number;
	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		cin>>number;
		lengtha=number.length();
		if(number=="1" || number=="4" || number=="78"){
			cout<<"+"<<endl;
		}
		else if( number[lengtha-1]=='5' && number[lengtha-2]=='3'){
			cout<<"-"<<endl;
		}
		else if( number[0]=='9' && number[lengtha-1]=='4'){
			cout<<"*"<<endl;
		}
		else{
			cout<<"?"<<endl;
		}
	}
	return 0;
}