#include<iostream>

using namespace std;

int main(int argc,char **argv){
	string name;
	int counter=1;
	cin>>name;
	while(name!="#"){ 
     	if(name=="HELLO"){  
        	printf("Case %d: ENGLISH\n",counter);
        }
		else if(name== "HOLA"){  
        	printf("Case %d: SPANISH\n",counter);  
        }
     	else if(name=="HALLO"){  
        	printf("Case %d: GERMAN\n",counter);
        }
     	else if(name=="BONJOUR"){  
        	printf("Case %d: FRENCH\n",counter);  
        }
     	else if(name=="CIAO"){  
        	printf("Case %d: ITALIAN\n",counter);  
        }
     	else if(name=="ZDRAVSTVUJTE"){  
        	printf("Case %d: RUSSIAN\n",counter);  
        }
        else{
        	printf("Case %d: UNKNOWN\n",counter); 
        }

    	counter++;
		cin>>name;
	}
	return 0;
}