#include<iostream>
#include<string>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;


bool compare(char first,char last){
	int firstAux,lastAux;

	if(first=='A') firstAux = '9'+5;
	else if(first=='K') firstAux ='9'+4;
	else if(first=='Q') firstAux ='9'+3;
	else if(first=='J') firstAux ='9'+2;
	else if(first=='T') firstAux ='9'+1;
	else firstAux = first;

	if(last=='A') lastAux = '9'+5;
	else if(last=='K') lastAux = '9'+4;
	else if(last=='Q') lastAux = '9'+3;
	else if(last=='J') lastAux = '9'+2;
	else if(last=='T') lastAux = '9'+1;
	else lastAux = last;

	if(firstAux<lastAux) return true;
	else return false;
}


typedef struct player{
	vector<char> clubs;
	vector<char> diamonds;
	vector<char> spades;
	vector<char> hearts;

	void sorting(){
		sort(this->clubs.begin(),this->clubs.end(),compare);
		sort(this->diamonds.begin(),this->diamonds.end(),compare);
		sort(this->hearts.begin(),this->hearts.end(),compare);
		sort(this->spades.begin(),this->spades.end(),compare);
	}

	void cleaning(){
		this->clubs.clear();
		this->hearts.clear();
		this->spades.clear();
		this->diamonds.clear();
	}

	void printing(){
		vector<char>::iterator it;
		for(it=clubs.begin();it!=clubs.end();it++){
			cout<<" C"<<*it;
		}for(it=diamonds.begin();it!=diamonds.end();it++){
			cout<<" D"<<*it;
		}
		for(it=spades.begin();it!=spades.end();it++){
			cout<<" S"<<*it;
		}
		for(it=hearts.begin();it!=hearts.end();it++){
			cout<<" H"<<*it;
		}

	}

}player;

typedef struct card{
	char suit;
	char cardType;
}card;

int main(int argc,char **argv){

	char letter;
	char dealer;
	int control = 0;

	deque<card> cardsQueue;
	card letterQueue;
	player players[4];

	card aux;

	while(true){

		cin>>dealer;
		if(dealer=='#') return 0;
	
		for(int i = 0;i < 52;i++){

			cin>>letter; letterQueue.suit = letter;
			cin>>letter; letterQueue.cardType = letter;
			cardsQueue.push_front(letterQueue);
		}

		if(dealer=='N') control = 1;
		else if(dealer=='E') control = 2;
		else if(dealer=='S') control = 3;
		else control = 0;

		while(!cardsQueue.empty()){
			aux = cardsQueue.back();
			cardsQueue.pop_back();
			if(aux.suit == 'C') players[control].clubs.push_back(aux.cardType);
			else if(aux.suit =='D') players[control].diamonds.push_back(aux.cardType);
			else if(aux.suit == 'H') players[control].hearts.push_back(aux.cardType);
			else if(aux.suit =='S') players[control].spades.push_back(aux.cardType);
			control = (control+1)%4;
		}
		players[0].sorting();
		players[1].sorting();
		players[2].sorting();
		players[3].sorting();

		cout<<"S:"; players[2].printing();cout<<endl;
		cout<<"W:"; players[3].printing();cout<<endl;
		cout<<"N:"; players[0].printing();cout<<endl;
		cout<<"E:"; players[1].printing();cout<<endl;

		players[0].cleaning();
		players[1].cleaning();
		players[2].cleaning();
		players[3].cleaning();
		cardsQueue.clear();

	}
	
	return 0;
}