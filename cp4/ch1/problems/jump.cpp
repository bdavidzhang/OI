//jump.cpp
#include<cstdio>
int main(){
   int t;
   int n;
   int hj, lj;
   int cur;
   int x;
   scanf("%d",&t);
   for (int j = 1; j <= t; ++j){
       hj = 0; lj = 0;
       scanf("%d",&n);
       scanf("%d",&cur);
       for (int i = 0; i < n-1; ++i){
            scanf("%d",&x);
            if(cur < x){
                hj++;
                cur = x;
            }
            else if (cur > x){
                lj++;
                cur = x;
            }
       }
       printf("Case %d: %d %d\n", j, hj, lj);

   }
   return 0;
}
