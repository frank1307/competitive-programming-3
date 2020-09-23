#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(int argc,char ** argv){
	int nQuery1;
	int nQuery2;
	int a,b,c;
	int sum;
	cin>>nQuery1;
	for(int i=0;i<nQuery1;i++){
		sum=0;
		cin>>nQuery2;
		for(int j=0;j<nQuery2;j++){
			cin>>a>>b>>c;
			sum+=a*c;
		}
		cout<<sum<<endl;
	}
	return 0;
}