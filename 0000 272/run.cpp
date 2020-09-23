#include<iostream>


using namespace std;

int main(int argc,char ** argv){
	char aux;
	bool open=false;
	while(cin>>aux){
		if(aux=='"'){
			if(open==false){
				open=true;
				cout<<"``";
			}
			else{
				cout<<"''";
				open=false;
			}
		}
		else{
			cout<<aux;
		}
	}
	return 0;
}