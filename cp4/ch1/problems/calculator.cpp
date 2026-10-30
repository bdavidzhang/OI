//test score calculator function
#include<cstdio>

int score(int a){
    if (a < 10) return a;
    return score(a % 10 + score(a/10));
}

int main(){
    int x;
    while(scanf("%d",&x)!=EOF){
    printf("%d\n",score(x));
    }
    return 0;
}

