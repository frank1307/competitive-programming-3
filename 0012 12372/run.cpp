#include<iostream>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,a,b,c;
	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		cin>>a>>b>>c;
		if(a<=20 && b<=20 && c<=20){
			printf("Case %d: good\n",i+1);
		}
		else{
			printf("Case %d: bad\n",i+1);
		}
	}
	return 0;
}