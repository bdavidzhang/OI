#include<cstdio>

int main(){
    int n;
    scanf("%d", &n);
    int arr[100000];  
    for(int i = 1; i <= n; ++i){
        scanf("%d", &arr[i]);
    }

    bool flag = true;
    for (int i =1; i <=n; ++i){
        int sum = 0; 
        for (int j = i; j <= n; j+=i){
            sum += arr[j];
        }
        if (sum % i != 0) flag = false; 
    }
   if(flag) printf("true\n");
   else printf("false\n");
    return 0;
}
