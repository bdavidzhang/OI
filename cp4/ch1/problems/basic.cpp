//basic programming .cpp
#include<cstdio>
#include<iostream>
#include<vector>
int main(){
    int n, t;
    std::cin>>n>>t;
    int arr[200005];
    for (int i = 0; i < n; ++i){
        scanf("%d",&arr[i]);
    }
    if (t == 1) printf("7\n");
    else if ( t==2){
        if (arr[0] > arr[1]) printf("Bigger\n");
        else if (arr[0] == arr[1]) printf("Equal\n");
        else prinf("Smaller\n");
    }
    else if (t==3){
        
