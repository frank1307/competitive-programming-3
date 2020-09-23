#include<iostream>

using namespace std;

int main(int argc,char ** argv){
	int init,first,second,third;
	cin>>init>>first>>second>>third;
	while(init || first || second ||third ){
		cout<<720+360+((init-first+40)%40+(second-first+40)%40+(second-third+40)%40)*(360/40)<<endl;
		cin>>init>>first>>second>>third;
	}
	return 0;
}