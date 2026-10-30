//moose.cpp
#include<cstdio>
#include<algorithm>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if (a == 0 & b == 0) printf("Not a moose");
    else if(a == b && a != 0) printf("Even %d",2*a); 
    else printf("Odd %d",std::max(a,b)*2);
    return 0;
}



