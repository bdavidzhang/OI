//nessy.cpp
#include<cstdio>
#include<cmath>


int main(){ 
    int t;
    int a,b;
    scanf("%d",&t);
    while(t--){
       scanf("%d%d",&a,&b); 
       printf("%d\n", (a/3)*(b/3));
    }
    return 0;
}


