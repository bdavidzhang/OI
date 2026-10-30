//dominion game 
#include<cstdio>
int main(){
    int g,s,c,sum = 0;
    scanf("%d%d%d",&g,&s,&c);
    sum = g*3+s*2+c*1;
    if(sum < 2)printf("Copper");
    else if(sum == 2) printf("Estate or Copper"); 
    else if(sum == 3 || sum == 4) printf("Estate or Silver"); 
    else if(sum == 5) printf("Duchy or Silver");
    else if(sum == 6 || sum == 7) printf("Duchy or Gold");
    else if(sum > 7) printf("Province or Gold");
    return 0;
}


