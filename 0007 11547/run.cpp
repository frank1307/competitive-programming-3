#include<iostream>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,n;
	cin>>nQuery;
	for(int i=0;i<nQuery;i++){
		cin>>n;
		n=n*567;
		n=n/9;
		n=n+7492;
		n=n*235;
		n=n/47;
		n=n-498;
		n=n%100;
		n=n/10;
		if(n>0){
			cout<<n<<endl;
		}
		else{
			n=-1*n;
			cout<<n<<endl;
		}
	}
	return 0;
}