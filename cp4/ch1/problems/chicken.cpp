//Dr. Chaz's chicken buffet!
#include<cstdio>
int main(){
    int a,b;//a -> people, b -> chicken
    scanf("%d%d",&a,&b);
    if(b > a+1)printf("Dr. Chaz will have %d pieces of chicken left over!", b-a);
    else if( b == a+1) printf("Dr. Chaz will have 1 piece of chicken left over!");
    else if( a == b+1) printf("Dr. Chaz needs 1 more piece of chicken!");

    else printf("Dr. Chaz needs %d more pieces of chicken!",a-b);

    return 0;
}
