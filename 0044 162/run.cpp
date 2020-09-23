#include<iostream>
#include<map>
#include<deque>

using namespace std;

bool isCardSpecial(string card){
	if(card[1] == 'J' || card[1] == 'Q' || card[1] == 'K' || card[1] == 'A'){
		return true;
	}
	else{
		return false;
	}
}

int howSpecialItIs(string card){
	if(card[1] == 'J') return 1;
	else if(card[1] =='Q') return 2;
	else if(card[1] =='K') return 3;
	else return 4;

}

void moveDeck(deque<string> &a, deque<string> &b){
	while(!b.empty()){ //you gotta realize that once the deck is taken, he is turned upside down
		a.push_back(b.back());
		b.pop_back();
	}
}


int main(int argc,char ** argv){
	string d;
	string nD;
	string card;

	int cardMoves; // how many moves does a player must do?
	bool specialCard; // is it a special card on? in the beginning no

	int play;
	
	deque<string> players[2]; 
	deque<string> deck; // pile deck
	
	while(1){
		for(int i = 0; i < 26; i++ ){
			cin>>nD;
			if(nD=="#"){ //ending string
				return 0; //finish program
			}
			cin>>d;
			players[0].push_front(nD); //non dealer
			players[1].push_front(d); //dealer
		}

		cardMoves = 1;
		specialCard = false;
		play = 0;
		
		while(true){

			if(players[play].empty()){
				break;
			}

			card = players[play].front(); //take card
			players[play].pop_front(); // remove card from players
			deck.push_front(card); //insert card into deck

			cardMoves--; //round was finished 

			if(isCardSpecial(card)){
				cardMoves = howSpecialItIs(card); //number of rounds must be refreshed
				specialCard = true;
				play = (play+1)%2;
			}

			if(!cardMoves){ //were all round cards taken?
				play = (play+1)%2; //move turn to the other players
				cardMoves++; // refresh moves 
				if(specialCard){ //is special mode on?
					moveDeck(players[play],deck); //special card round winner takes all cards on deck
					specialCard = false; //put the special mode off
				}
			}


		}

		if(play==0){
			printf("1%3d\n",int(52-deck.size()));
		}
		else{
			printf("2%3d\n",int(52-deck.size()));
		}

		deck.clear();
		players[0].clear();
		players[1].clear();

	}
	return 0;
}