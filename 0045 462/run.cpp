#include<iostream>
#include<vector>
#include <sstream> 
#include <algorithm>
#include <map>

using namespace std;

//ctrl+shift+/ to comment blocks of code

//it returns the points that a suit has and if the suit is stopped
pair<int,bool> addSpecialCardValues(vector<string> a){
	vector<string>::iterator it;
	int sum = 0;
	bool ace = false;
	bool king = false;
	bool queen = false;
	bool jack = false;
	for(it=a.begin();it!=a.end();it++){
		string aux = *it;
		if(aux[0]=='A'){
			ace = true;
			sum +=4;
		}
		else if(aux[0]=='K'){
			king = true;
			sum += 3;
		}
		else if(aux[0]=='Q'){
			sum += 2;
			queen = true;
		}
		else if(aux[0]=='J'){
			sum += 1;
			jack = true;
		}
	}
	if(king ==true && a.size()==1){
		sum-=1;
	}
	if(queen ==true && a.size()<=2){
		sum-=1;
	}
	if(jack==true && a.size()<=3){
		sum-=1;
	}
	if(a.size()==2){
		sum+=1;
	}
	if(a.size()<=1){
		sum+=2;
	}

	if(ace || (king && a.size()>=2) || (queen && a.size()>=3)){
		return make_pair(sum,true);
	}
	else{
		return make_pair(sum,false);
	}

}

//if all suits are stopped, then we must subtract rules 5 6 7 points
int subtractStopped(vector<string> v){
	if(v.size()==2) return 1;
	else if(v.size()<=1) return 2;
	else return 0;
}

//if bid has been chosen, this chooses the suit with most cards to use in the bid
string getBiggerSuit(vector<string> spades,vector<string> hearts,vector<string> diamonds,vector<string> clubs){
	int suits[4]= {spades.size(),hearts.size(),diamonds.size(),clubs.size()};
	
	int maxIndex = 0;
	int max=spades.size();
	for(int i=0;i<4;i++){
		if(suits[i]>max){
			max=suits[i];
			maxIndex= i;
		}
	}

	if(maxIndex==0) return "S";
	if(maxIndex==1) return "H";
	if(maxIndex==2) return "D";
	if(maxIndex==3) return "C";

/*	map<string,int> mp;
	mp["S"] = spades.size();
	mp["H"] = hearts.size();
	mp["D"] = diamonds.size();
	mp["C"] = clubs.size();
	map<string,int>::iterator it;
	map<string,int>::iterator max = mp.begin();
	for(it=mp.begin();it!=mp.end();it++){
		if( it->second > max->second){
			max = it;
		}
	}
	return max->first; */
}

//it chooses the final answer
string chooseBid(vector<string> clubs,vector<string> hearts,vector<string> diamonds,vector<string> spades){
	pair<int,bool> clubsAnswer    = addSpecialCardValues(clubs);   
	pair<int,bool> heartsAnswer   = addSpecialCardValues(hearts);
	pair<int,bool> diamondsAnswer = addSpecialCardValues(diamonds);
	pair<int,bool> spadesAnswer   = addSpecialCardValues(spades);

	int sum = get<0>(clubsAnswer)+get<0>(heartsAnswer)+get<0>(diamondsAnswer)+get<0>(spadesAnswer); //the total amount of points of a hand

	if(sum<14) return "PASS"; //pass hand

	if(get<1>(clubsAnswer) && get<1>(heartsAnswer) && get<1>(diamondsAnswer) && get<1>(spadesAnswer)){//if all suits are stopped
		int sub = subtractStopped(clubs)+subtractStopped(hearts)+subtractStopped(diamonds)+subtractStopped(spades); //substracting rule 5 6 7 points
		sum-=sub;
		if(sum>=16) return "BID NO-TRUMP";
		else sum+=sub; //adding back rule 5 6 7 points if 16 is not achieved
	}
	if(sum>=14) return "BID "+getBiggerSuit(spades,hearts,diamonds,clubs);
}

int main(int argc, char ** argv){
	string aux;

	vector<string> clubs;
	vector<string> diamonds;
	vector<string> hearts;
	vector<string> spades;

	stringstream ss;

	while(getline(cin,aux)){
		ss<<aux;
		for (int i = 0; i <13; ++i){
			ss>>aux;

			if(aux[1]=='C') clubs.push_back(aux);
			else if(aux[1]=='D') diamonds.push_back(aux);
			else if(aux[1]=='H') hearts.push_back(aux);
			else spades.push_back(aux);
		}

		cout<< chooseBid(clubs,hearts,diamonds,spades)<<endl;
		clubs.clear();
		diamonds.clear();
		hearts.clear();
		spades.clear();
		ss.clear();
	}
	return 0;
}