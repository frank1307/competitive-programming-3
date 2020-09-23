#include<iostream>

using namespace std;

int main(int argc,char ** argv){
	int iterations,m,n,aux;
	cin>>iterations;

	for(int i = iterations ; i > 0 ; i--){
		cin>>m>>n;
		m= (m-2)/3 + ((m-2) % 3 == 0 ? 0 : 1); 
		n= (n-2)/3 + ((n-2) % 3 == 0 ? 0 : 1);
		cout<<n<<endl;
	}
	return 0;
}