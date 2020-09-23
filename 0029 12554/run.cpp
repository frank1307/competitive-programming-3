#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

int main(int argc,char **argv){
string s[16];
s[0]="Happy";s[1]= "birthday";s[2]="to";s[3]="you";s[4]="Happy";s[5]="birthday";s[6]="to";
s[7]="you";s[8]="Happy";s[9]="birthday";s[10]="to";s[11]="Rujia";s[12]="Happy";s[13]="birthday";
s[14]="to";s[15]="you";

int numberPeople;
cin>>numberPeople;
string people[numberPeople];

for(int i=0;i<numberPeople;i++){
	cin>>people[i];
}
int i,j;
cout<<people[0]<<": "<<s[0]<<endl;
i=j=1;
while( (j/numberPeople)<1  || (i%16)!=0){
	cout<<people[j%numberPeople]<<": "<<s[j%16]<<endl;
	i++;
	j++;
}

return 0;
}