#include <iostream>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,reason,counter,cCase;
	counter=0;
	cCase=1;
	cin>>nQuery;
	while(nQuery!=0){
		for(int i=0;i<nQuery;i++){
			cin>>reason;
			
			if(reason>=1 && reason<=99){
				counter++;
			}
			else{
				counter--;
			}

		}
		printf("Case %d: %d\n",cCase,counter);
		cin>>nQuery;
		cCase++;
		counter=0;
	}
	return 0;
}