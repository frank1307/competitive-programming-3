#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main(int argc,char ** argv){
	double downPayment, amount, value, depreciation, paymentMonthList[101], monthPayment;
	
	int numberOfPayments, numberOfCases, month, begin, end;
	
	vector <tuple<int,double>> paymentList;
	vector<tuple<int,double>>::iterator ite;

	cin>>numberOfPayments>>downPayment>>amount>>numberOfCases;
	
	while(numberOfPayments>=0){
		for(int i = 0; i < numberOfCases; i++){
			cin>>month>>depreciation;
			paymentList.push_back(make_tuple(month,depreciation));
		}

		reverse(paymentList.begin(),paymentList.end());
		end=numberOfPayments;

		for(ite=paymentList.begin();ite!=paymentList.end();ite++){
			
			tuple<int,double> myTuple=*ite;
			begin= get<0>(myTuple);
			depreciation= get<1>(myTuple);

			for(int i=begin;i<=end;i++){
				paymentMonthList[i]=depreciation;
			}
			end=begin-1;
		}

		value=amount+downPayment;
		monthPayment=amount/numberOfPayments;
		value=value*(1-paymentMonthList[0]);
		month=0;
		
		if(value>amount){
			month=0;
		}
		else{
			for(int i=1;i<=numberOfPayments;i++){
				
				amount=amount-monthPayment;
				value=value*(1-paymentMonthList[i]);
				
				if(value>amount){
					month=i;
					break;
				}
			}
		}

		if(month==1){
			printf("%d month\n",month);
		}
		else{
			printf("%d months\n",month);
		}
		
		cin>>numberOfPayments>>downPayment>>amount>>numberOfCases;
		paymentList.clear();
	}
	return 0;
}