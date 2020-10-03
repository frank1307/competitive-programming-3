#include<iostream>
#include<sstream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct card{
	char suit;
	int value;
}card;


typedef struct xyz{
	int smaller;
	int middle;
	int bigger;
	int evenSmaller;
	int hellSmaller;
}xyz;

int assignValue(char a){
	if(a=='A') return 14;
	else if(a=='K') return 13;
	else if(a=='Q') return 12;
	else if(a=='J') return 11;
	else if(a=='T') return 10;
	else return a -'0';
}
xyz getOrderedCardsLAST(card * player){
	vector<int> vec;
	for(int i=0;i<5;i++)
		vec.push_back(player[i].value);
	sort(vec.begin(),vec.end());
	xyz boring;
	boring.bigger=vec[4];
	boring.middle=vec[3];
	boring.smaller=vec[2];
	boring.evenSmaller=vec[1];
	boring.hellSmaller=vec[0];
	return boring;
}
pair<bool,int> checkStraightFlush(card * player){
	if(player[0].suit==player[1].suit && player[0].suit == player[2].suit && player[0].suit == player[3].suit && player[0].suit == player[4].suit){}
	else return make_pair(false,0);

	vector<int> vec;
	for(int i=0;i<5;i++){
		vec.push_back(player[i].value);
	}

	sort(vec.begin(),vec.end());
	
	for(int i=1;i<5;i++){
		if((vec[i]-1)!=vec[i-1]) return make_pair(false,0);
	}

	return make_pair(true,vec[4]);
}
pair<bool,int> checkFourOfKind(card * player){
	map<int,int> mapa;
	for(int i=0;i<5;i++){
		if( mapa.find(player[i].value) == mapa.end() ){
			mapa[player[i].value]=1;
		}
		else{
			mapa[player[i].value]+=1;
		}
	}
	map<int,int>::iterator it;
	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second>=4) 
			return make_pair(true,it->first);
	}
	return make_pair(false,0);
}
pair<bool,int> checkFullHouse(card * player){
	map<int,int> mapa;
	map<int,int>::iterator it;

	for(int i=0;i<5;i++){
		if(mapa.find(player[i].value) == mapa.end())
			mapa[player[i].value]=1;
		else
			mapa[player[i].value]+=1;
	}

	if(mapa.size()!=2) return make_pair(false,0);

	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second==3)
			return make_pair(true,it->first);
	}
	return make_pair(false,0);
}
pair<bool,int> checkFlush(card * player){
	int max=0;
	for(int i=0;i<5;i++) 
		if(player[i].value>max) max = player[i].value;
	for(int i=1;i<5;i++)
		if(player[i].suit!=player[i-1].suit)
			return make_pair(false,0);

	return make_pair(true,max);
}
pair<bool,int> checkThreeOfKind(card * player){
	map<int,int> mapa;
	for(int i=0;i<5;i++){
		if(mapa.find(player[i].value)==mapa.end())
			mapa[player[i].value]=1;
		else 
			mapa[player[i].value]+=1;
	}
	map<int,int>::iterator it;
	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second>=3){
			return make_pair(true,it->first);
		}
	}
	return make_pair(false,0);
}
pair<bool,int> checkTwoPairs(card * player){
	map<int,int> mapa;
	int twoPairs = 0;
	for(int i=0;i<5;i++){
		if(mapa.find(player[i].value)==mapa.end())
			mapa[player[i].value]=1;
		else 
			mapa[player[i].value]+=1;
	}

	map<int,int>::iterator it;
	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second==2){
			twoPairs++;
		}
	}

	if(twoPairs!=2) return make_pair(false,0);
	int max = 0;

	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second==2 && it->first>max){
			max=it->first;
		}
	}

	return make_pair(true,max);
}
pair<bool,int> checkPair(card * player){
	map<int,int> mapa;
	for(int i=0;i<5;i++){
		if(mapa.find(player[i].value)==mapa.end())
			mapa[player[i].value]=1;
		else 
			mapa[player[i].value]+=1;
	}

	map<int,int>::iterator it;
	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second==2){
			return make_pair(true,it->first);
		}
	}
	return make_pair(false,0);
}
int getHighCard(card * player){
	int max = 0;
	for(int i=0;i<5;i++)
		if(player[i].value > max)
			max = player[i].value;
	return max;
}
pair<int,int> playerStatus(card * player){
	pair<int,int> answer = checkStraightFlush(player);
	if(get<0>(answer)) 
		return make_pair(7,get<1>(answer));

	answer = checkFourOfKind(player);
	if(get<0>(answer)) 
		return make_pair(6,get<1>(answer));

	answer = checkFullHouse(player);
	if(get<0>(answer)) 
		return make_pair(5,get<1>(answer));

	answer = checkFlush(player);
	if(get<0>(answer)) 
		return make_pair(4,get<1>(answer));

	answer = checkThreeOfKind(player);
	if(get<0>(answer)) 
		return make_pair(3,get<1>(answer));

	answer = checkTwoPairs(player);
	if(get<0>(answer)) 
		return make_pair(2,get<1>(answer));

	answer = checkPair(player);
	if(get<0>(answer)) 
		return make_pair(1,get<1>(answer));
	
	return make_pair(0,getHighCard(player));
}
pair<int,int> getSmallerPair(card * player){
	map<int,int> mapa;
	for(int i=0;i<5;i++){
		if(mapa.find(player[i].value)==mapa.end())
			mapa[player[i].value]=1;
		else 
			mapa[player[i].value]+=1;
	}

	map<int,int>::iterator it;
	int minPair= 14;

	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second==2 && it->first<minPair){
			minPair=it->first;
		}
	}
	int nonPair = 0;
	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second!=2){
			nonPair=it->first;
		}
	}
	return make_pair(minPair,nonPair);
}
xyz getOrderedCards(card * player){
	vector<int> vec;
	map<int,int> mapa;
	for(int i=0;i<5;i++){
		if(mapa.find(player[i].value)==mapa.end())
			mapa[player[i].value]=1;
		else 
			mapa[player[i].value]+=1;
	}

	map<int,int>::iterator it;
	int minPair= 14;

	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second==2 && it->first<minPair){
			minPair=it->first;
		}
	}
	int nonPair = 0;
	for(it=mapa.begin();it!=mapa.end();it++){
		if(it->second!=2){
			vec.push_back(it->first);
		}
	}
	sort(vec.begin(),vec.end());
	xyz a;
	a.smaller = vec[0];
	a.middle= vec[1];
	a.bigger = vec[2];
	return a;
}
void winner(card * player1,card * player2){
	pair<int,int> p1 = playerStatus(player1);
	pair<int,int> p2 = playerStatus(player2);
	if(get<0>(p1) > get<0>(p2))
		cout<<"Black wins."<<endl;
	else if( get<0>(p1) < get<0>(p2) )
		cout<<"White wins."<<endl;
	else 
		if(get<0>(p1) == 1){

			if(get<1>(p1)>get<1>(p2)){
				cout<<"Black wins."<<endl;
				return;
			}
			else if( get<1>(p1)<get<1>(p2)){
				cout<<"White wins."<<endl;
				return;
			}
			xyz p_1=getOrderedCards(player1);
			xyz p_2=getOrderedCards(player2);

			if(p_1.bigger>p_2.bigger) cout<<"Black wins."<<endl;
			else if(p_1.bigger<p_2.bigger) cout<<"White wins."<<endl;
			else if(p_1.middle>p_2.middle)cout<<"Black wins."<<endl;
			else if(p_1.middle<p_2.middle) cout<<"White wins."<<endl;
			else if(p_1.smaller>p_2.smaller) cout<<"Black wins."<<endl;
			else if(p_1.smaller<p_2.smaller) cout<<"White wins."<<endl; 
			else cout<<"Tie."<<endl;
		}
		else if(get<0>(p1) == 2){

			if(get<1>(p1)>get<1>(p2)){
				cout<<"Black wins."<<endl;
				return;
			}
			else if( get<1>(p1)<get<1>(p2)){
				cout<<"White wins."<<endl;
				return;
			}

			p1=getSmallerPair(player1);
			p2=getSmallerPair(player2);
			if(get<0>(p1)>get<0>(p2))
				cout<<"Black wins."<<endl;
			else if(get<0>(p1)<get<0>(p2))
				cout<<"White wins."<<endl;
			else 
				if(get<1>(p1)>get<1>(p2))
					cout<<"Black wins."<<endl;
				else 
					if(get<1>(p1)<get<1>(p2))
						cout<<"White wins."<<endl;
					else 
						cout<<"Tie."<<endl;
		}
		else if(get<0>(p1) == 0 || get<0>(p1) == 4){
			xyz p_1=getOrderedCardsLAST(player1);
			xyz p_2=getOrderedCardsLAST(player2);
			if(p_1.bigger>p_2.bigger) cout<<"Black wins."<<endl;
			else if(p_1.bigger<p_2.bigger) cout<<"White wins."<<endl;
			else if(p_1.middle>p_2.middle) cout<<"Black wins."<<endl;
			else if(p_1.middle<p_2.middle) cout<<"White wins."<<endl;
			else if(p_1.smaller>p_2.smaller) cout<<"Black wins."<<endl;
			else if(p_1.smaller<p_2.smaller) cout<<"White wins."<<endl;
			else if(p_1.evenSmaller>p_2.evenSmaller) cout<<"Black wins."<<endl;
			else if(p_1.evenSmaller<p_2.evenSmaller) cout<<"White wins."<<endl;
			else if(p_1.hellSmaller>p_2.hellSmaller) cout<<"Black wins."<<endl;
			else if(p_1.hellSmaller<p_2.hellSmaller) cout<<"White wins."<<endl;
			else cout<<"Tie."<<endl;							
		}
		else{
			if( get<1>(p1) > get<1>(p2) )
				cout<<"Black wins."<<endl;
			else if( get<1>(p1) < get<1>(p2))
				cout<<"White wins."<<endl;
			else
				cout<<"Tie."<<endl;
		}
}


int main(int argc,char **argv){
	stringstream ss;
	string s;
	card player1[5];
	card player2[5];

	while(true){
		getline(cin,s);
		if(s=="") break;
		ss<<s;

		for(int i=0;i<5;i++){
			ss>>s;
			player1[i].suit = s[1];
			player1[i].value= assignValue(s[0]);
		}

		for(int i=0;i<5;i++){
			ss>>s;
			player2[i].suit = s[1];
			player2[i].value= assignValue(s[0]);
		}

		winner(player1,player2);
		ss.clear();
	}
	cout<<endl;
	return 0;
}

