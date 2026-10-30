//langdet.cpp
#include<cstdio>
#include<iostream>
int main(){
    int cnt=0;
    std::string s;
    scanf("%d",&cnt);
    while(std::getline(std::cin,s)){
        cnt++;
        if(s[0] == '#' && s.size() == 1) return 0;
        if (s == "HELLO") printf("Case %d: ENGLISH\n",cnt);
        else if (s == "HOLA") printf("Case %d: SPANISH\n",cnt);
        else if (s == "HALLO") printf("Case %d: GERMAN\n", cnt);
        else if (s == "BONJOUR") printf("Case %d: FRENCH\n", cnt);
        else if (s == "CIAO") printf("Case %d: ITALIAN\n", cnt);
        else if (s == "ZDRAVSTVUJTE") printf("Case %d: RUSSIAN\n", cnt);
        else printf("Case %d: UNKNOWN\n", cnt);
    }
    return 0;
}
