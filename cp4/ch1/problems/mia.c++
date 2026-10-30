//mia cpp
#include<cstdio>
#include<algorithm>
int main(){
    int s0,s1,r0,r1,s,r;
    while(scanf("%d%d%d%d",&s0,&s1,&r0,&r1)){
    if (s0 == 0 && s1 == 0 && r0 == 0 && r1 == 0) return 0;
    s = std::max(s0,s1)*10+std::min(s0,s1);
    r = std::max(r0,r1)*10+std::min(r0,r1);
    if (s == 21){
        if (r == 21){
            printf("Tie.\n");
        }else{
          printf("Player 1 wins.\n");  
        }
    }
    else if(s % 11 == 0){
         if (r == 21){
            printf("Player 2 wins.\n");
        }else if (r % 11 == 0){
          if (s > r) printf("Player 1 wins.\n");
          else if (s == r) printf("Tie.\n");
          else printf("Player 2 wins.\n");
        }else{
           printf("Player 1 wins.\n"); 
        }
    }
    else{
        if (r == 21 || r % 11 == 0) printf("Player 2 wins.\n");
        else { 
        if (s > r) printf("Player 1 wins.\n");
        else if (s == r) printf("Tie.\n");
        else printf("Player 2 wins.\n");
        }
    }   
}
}
