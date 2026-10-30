#include<cstdio>
#include<algorithm>


int main(){
    
    int n;
    scanf("%d", &n);
    int arr[n];
    int a = n;
    while (a--){
    scanf("%d",&arr[a--]);
    }

    std::sort(arr[0],arr[n-1]);
    while(a++ < n){
    printf("%d",arr[a]);
    }

    return 0;
}
