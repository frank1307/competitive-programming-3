#include<iostream>

using namespace std;

int main(int argc,char ** argv){
	int nQuery,x,y,x1,x2,y1,y2;
	cin>>nQuery;
	while(nQuery!=0){
		cin>>x>>y;
		for(int i=0;i<nQuery;i++){
			cin>>x1>>y1;
			if(x1==x || y1==y){
				cout<<"divisa"<<endl;
				continue;
			}
			if(x1>x){
				if(y1>y){
					cout<<"NE"<<endl;
				}
				else{
					cout<<"SE"<<endl;
				}	
			}
			else{
				if(y1>y){
					cout<<"NO"<<endl;
				}
				else{
					cout<<"SO"<<endl;
				}
			}

		}
		cin>>nQuery;
	}
	return 0;
}