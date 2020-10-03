#include<iostream>
#include<string>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

void changeDeck(int * deck,int * deckChanger){
	int decka[52];
	for(int i=0;i<52;i++){
		decka[i] = deck[deckChanger[i]-1];
	}
	for(int i=0;i<52;i++){
		deck[i]=decka[i];
	}
}

void initializeDeck(int *deck){
	int b=2;
	for(int i=0;i<=12;i++){
		deck[i] = b;
		b++;
	}
	b=102;
	for(int i=13;i<=25;i++){
		deck[i] = b;
		b++;
	}
	b=202;
	for(int i=26;i<=38;i++){
		deck[i] = b;
		b++;
	}
	b=302;
	for(int i=39;i<52;i++){
		deck[i] = b;
		b++;
	}
}

void printAux(int a,string s){
	if(a==11) cout<<"Jack of "<<s<<endl;
	else if(a==12) cout<<"Queen of "<<s<<endl;
	else if(a==13) cout<<"King of "<<s<<endl;
	else if(a==14) cout<<"Ace of "<<s<<endl;
	else cout<<a<<" of "<<s<<endl;
}

void printing(int * deck){
	for(int i=0;i<52;i++){
		if(deck[i]>=2 && deck[i]<100){
			printAux(deck[i],"Clubs");
		}
		else if(deck[i]>=102 && deck[i]<200){
			deck[i]-=100;
			printAux(deck[i],"Diamonds");
		}
		else if(deck[i]>=202 && deck[i]<300){
			deck[i]-=200;
			printAux(deck[i],"Hearts");
		}
		else{
			deck[i]-=300;
			printAux(deck[i],"Spades");
		}
	}
}
int main(int argc,char ** argv){
	int n;
	int nShuffles = 0;
	int deck[52];
	int ** shuffles;
	
	string s;
	cin>>n;

	for(int i = 0 ; i < n ; i++){
		
		initializeDeck(deck);

		cin>>nShuffles;

		shuffles =(int **)malloc(nShuffles*sizeof(int *));
		
		for(int j=0;j<nShuffles;j++){
			shuffles[j]=(int *)malloc(52*sizeof(int));
		}

		for(int j = 0 ; j < nShuffles ; j++){
			for(int k = 0 ; k < 52 ; k++){
				cin>>shuffles[j][k];
			}
		}
		cin.ignore();
		while(true){
			getline(cin,s);
			if(s=="") break;
			changeDeck(deck,shuffles[stoi(s)-1]);
		}
		for(int j=0;j<nShuffles;j++){
			free(shuffles[j]);
		}
		free(shuffles);
		if(i!=0) cout<<endl;
		printing(deck);
	}


	return 0;
}