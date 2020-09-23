#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <map>
#include <algorithm>

using namespace std;

int recursive(int i,string number){
    if(to_string(number.length()) == number){
        return i;
    }
    i++;
    return recursive(i,to_string(number.length()));
}




int main(int argc,char ** argv){
    string input;
    cin>>input;

    while(input!="END"){
        printf("%d\n", recursive(1,input));
   		cin>>input;
    }

    return 0;
}