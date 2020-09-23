#include<iostream>

using namespace std;

int main(int argc,char **argv){
	int ite,nCases,smaller,bigger,aux;
	cin>>ite;
	for(int i=0;i<ite;i++){
		smaller=99;
		bigger=0;
		cin>>nCases;
		for(int j=0;j<nCases;j++){
			cin>>aux;
			if(aux<smaller){
				smaller=aux;
			}
			if(aux>bigger){
				bigger=aux;
			}
		}
		aux=bigger-smaller;
		aux=2*aux;
		cout<<aux<<endl;
	}	
	return 0;
}