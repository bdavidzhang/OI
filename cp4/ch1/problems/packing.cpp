//packing.cpp
#include<cstdio>

bool fits(int x){
    if (x <= 20 && x >= 1) return true;
    return false;
}

int main(){
    int t;
    int x,y,z;
    scanf("%d",&t);
    for (int i =1; i <= t; ++i){
        scanf("%d%d%d",&x,&y,&z);
        if(fits(x) && fits(y) && fits(z)) printf("Case %d: good\n",i);
        else printf("Case %d: bad\n",i);

    }
    return 0;
}
