#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int  sumOfDigits(long int  number){
	if((number/10)==0){
		return number;
	}
	long int  units;
	long int  tens;
	long int  hundreds;
	long int  thousands;
	long int  tenThousands;
	long int  oneHundredThousands;
	long int  millions;
	long int  tensMillions;
	long int  hundredsMillions;
	long int  billions;

	units=number%10;
	tens=(number%100)/10;
	hundreds=(number%1000)/100;
	thousands=(number%10000)/1000;
	tenThousands=(number%100000)/10000;
	oneHundredThousands=(number%1000000)/100000;
	millions=(number%10000000)/1000000;
	tensMillions=(number%100000000)/10000000;
	hundredsMillions=(number%1000000000)/100000000;
	billions=(number%10000000000)/1000000000;
	int sum=units+tens+hundreds+thousands+tenThousands+oneHundredThousands+millions+tensMillions+hundredsMillions+billions;

	return sumOfDigits(sum);


}

int  main(int  argc,char ** argv){
	long int  number;
	scanf("%ld",&number);
	while(number!=0){
		cout<<sumOfDigits(number)<<endl;
		scanf("%ld",&number);
	}
	return 0;
}