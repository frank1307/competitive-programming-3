#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
// NBHW

int main(int argc,char ** argv){
	int N,B,H,W;
	long int minCost;
	long int payment;
	long int totalPayment;
	int emptyBed;
	while(cin>>N>>B>>H>>W){
		minCost=B+1;
		for(int i=0;i<H;i++){
			cin>>payment;
			for(int j=0;j<W;j++){
				cin>>emptyBed;
				if(emptyBed>N){
					totalPayment=payment*N;
					if(minCost>totalPayment){
						minCost=totalPayment;
					}
					continue;
				}
			}
		}
		if(minCost>B){
			cout<<"stay home"<<endl;
		}
		else{
			cout<<minCost<<endl;
		}
		minCost=1000000;
	}
	return 0;
}