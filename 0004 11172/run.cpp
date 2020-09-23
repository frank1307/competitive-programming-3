#include<iostream>

using namespace std;

int main(int argc,char ** argv){
	int ite,first,second;
	cin>>ite;
	for(int i=0;i<ite;i++){
		cin>>first>>second;
		if(first>second){
			cout<<">"<<endl;
		}
		else{
			if(first<second){
				cout<<"<"<<endl;
			}
			else{
				cout<<"="<<endl;
			}
		}
	}
	return 0;
}