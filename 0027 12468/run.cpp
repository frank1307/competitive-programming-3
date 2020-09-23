#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main(int argc,char ** argv){
	int a,b;
	int right,left;
	cin>>a>>b;
	while(a!=-1 && b!=-1){
		if(a<b){
			right=b-a;
			left=a+100-b;
		}
		else if(a>b){
			right=a-b;
			left=b+100-a;
		}
		else{
			right=left=0;

		}
		if(right==left){
			cout<<right<<endl;
		}
		else if(right>left){
			cout<<left<<endl;
		}
		else{
			cout<<right<<endl;
		}

		cin>>a>>b;

	}
	return 0;
}