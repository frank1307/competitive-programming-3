#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>
#include <string>


using namespace std;

int makeOneDigitNumber(int number){
	int sum=0;
	if(number<=9){
		return number;
	}
	else{
		string temp=to_string(number);
		for(int i=0;i<temp.length();i++){
			sum+=temp[i]-'0';	
		}
	}

	return makeOneDigitNumber(sum);
}

int valueChar(char a){
	if( a>='a' && a<='z'){
		return (a%'a')+1;
	}
	else if(a>='A' && a<='Z'){
		return (a%'A')+1;
	}
	else{
		return 0;
	}
}



int stringSum(string name){
	int sum=0;
	for(int i=0;i<name.length();i++){
		sum+=valueChar(name[i]);
	}
	return makeOneDigitNumber(sum);
}

int main(int argc,char ** argv){
	string name1,name2;
	float value1,value2;
	while(getline(cin,name1)){
		getline(cin,name2);
		value1=stringSum(name1);
		value2=stringSum(name2);
		if(value1>value2){
			printf("%.2f %%\n",(value2/value1)*100);
		}
		else{
			printf("%.2f %%\n",(value1/value2)*100);
		}
	}
	return 0;
}