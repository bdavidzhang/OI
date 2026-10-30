//numbers don't matter
//I love you, because you are love
#include<iostream>
#include<cstdio>
#include<string>

int getscore(int a){
    if (a < 10) return a;
    return getscore(a%10+getscore(a/10));
}

int main(){
    std::string s1, s2; 
    int sum1,sum2;
    int ans1,ans2;
    double sol;
    while (std::getline(std::cin,s1)){
        std::getline(std::cin,s2);
        sum1 = 0;
        sum2 = 0;
        for (char c: s1){
            if (c >= 'a' && c <= 'z'){
                sum1 += static_cast<int>(c-'a'+1);
            }else if( c >= 'A' && c <= 'Z'){
                sum1 += static_cast<int>(c-'A'+1);
            }
        }
        for (char c: s2){
            if (c >= 'a' && c <= 'z'){
                sum2 += static_cast<int>(c-'a'+1);
            }else if( c >= 'A' && c <= 'Z'){
                sum2 += static_cast<int>(c-'A'+1);
            }
        }
        ans1 = getscore(sum1); 
        ans2 = getscore(sum2);
        sol = ans1/static_cast<double>(ans2);
        if (sol > 1){
            sol = ans2/static_cast<double>(ans1);
        }
        printf("%.2f %%\n", 100*sol);
    }
    return 0;
}


