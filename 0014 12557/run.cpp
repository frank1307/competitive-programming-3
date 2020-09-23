#include<iostream>

using namespace std;

int main(int argc,char ** argv){
	string name;
	int counter=1;
	cin>>name;
	while(name!="*"){
		if(name=="Hajj"){
			printf("Case %d: Hajj-e-Akbar\n",counter);
		}
		else{
			printf("Case %d: Hajj-e-Asghar\n",counter);
		}
		counter++;
		cin>>name;
	}
	return 0;
}