//eli.cpp
#include<cstdio>
#include<string>
#include<iostream>
int main(){
    int t;
    std::string s;
    int a,b,c,d,e,f,g;
    scanf("%d",&t);
    while (t--){
        std::cin >> s;
        scanf("%d/%d/%d %d/%d/%d %d",&a,&b,&c,&d,&e,&f,&g);
        if(a >= 2010 || d >= 1991) printf("%s eligible",s.c_str());
        else if (g >= 41) printf("%s ineligible",s.c_str());
        else printf("%s coach petition",s.c_str());
    }
    return 0;
}
