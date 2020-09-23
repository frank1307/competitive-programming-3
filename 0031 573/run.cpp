#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

pair<bool,int> simulateProcess(int H,int U,int D,int F){
	float position=0;
	int day=0;
	float climbedUp;
	while(true){
		climbedUp=U-day*F*U/100.0;
		if(position+climbedUp>H){
			return make_pair(true,day+1);
		}
		if(climbedUp>0){
			position+=climbedUp-D;
		}
		else{
			climbedUp=0;
			position-=D;
		}
		if(position<0){
			return make_pair(false,day+1);
		}
		else {
			day++;
		}
	}
}

int main(int argc,char ** argv){
	int H,U,D,F;
	cin>>H>>U>>D>>F;
	pair<bool,int> answer;
	while(H!=0){
		answer=simulateProcess(H,U,D,F);
		if(answer.first){
			cout<<"success on day "<<answer.second<<endl;
		}
		else{
			cout<<"failure on day "<<answer.second<<endl;
		}

	cin>>H>>U>>D>>F;
	}
	return 0;
}