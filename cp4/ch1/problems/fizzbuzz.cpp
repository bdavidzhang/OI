//fizzbuzz.cpp
//sieve
#include<cstdio>
#include<string>
int main(){
    int x,y,n;
    bool flagx, flagy;
    scanf("%d%d%d",&x,&y,&n);
    std::string s = "";
    for (int i = 1; i <= n; ++i){
        s = "";
        flagx=false;flagy=false;
        if(i % x == 0){
            s += "Fizz";
            flagx = true;
        }
        if(i % y == 0){
            s += "Buzz";
            flagy=true;
        }
        if(flagx == false && flagy == false) s += std::to_string(i);
        printf("%s\n",s.c_str());
    }
    return 0;
}
