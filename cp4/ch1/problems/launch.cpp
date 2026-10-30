//launch
#include<cstdio>
int main(){
    int n;
    int min = 2*1e9; 
    int flag;
    int x;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i){
       scanf("%d",&x);
       if(min > x){
           min = x; 
           flag = i;
       }
    }
    printf("%d\n",flag);
    return 0;
}



