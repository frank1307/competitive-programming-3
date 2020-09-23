#include<iostream>
#include <algorithm> 

using namespace std;

int main(int argc,char ** argv){
	int nQuery;
	int a[3];
	cin>>nQuery;

	for(int i=0;i<nQuery;i++){
		cin>>a[0]>>a[1]>>a[2];

		if(a[2]>a[1] && a[1]>a[0]){
//			cout<<"Case "<<i+1<<": "<<a[1]<<endl; its better to read in the c format output, cause it is most inteligible
			printf("Case %d: %d\n",i+1,a[1]);
			continue;
		}
		if(a[0]>a[1] && a[1]>a[2]){
			printf("Case %d: %d\n",i+1,a[1]);
			continue;
		}
		if(a[0]>a[2] && a[2]>a[1]){
			printf("Case %d: %d\n",i+1,a[2]);
			continue;
		}
		if(a[1]>a[2] && a[2]>a[0]){
			printf("Case %d: %d\n",i+1,a[2]);
			continue;
		}
		if(a[1]>a[0] && a[0]>a[2]){
			printf("Case %d: %d\n",i+1,a[0]);
			continue;
		}
		if(a[2]>a[0] && a[0]>a[1]){
			printf("Case %d: %d\n",i+1,a[0]);
			continue;
		}
	}
	return 0;
}