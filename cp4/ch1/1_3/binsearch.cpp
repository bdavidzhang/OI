//binary search
//
//for sorted array L
//returns index of number
#include<cstdio>

int bin_search(int* L,int start, int finish, int target){
    int mid = (start+finish)/2; 
    if (L[mid] == target) return mid;
    if (target > mid)
        return bin_search(L,mid,finish,target);
    else
        return bin_search(L,start,finish,target);
    return -1;
}

int main(){
    int arr[5] = {1,2,4,5,6};
    int a = bin_search(arr,0,5,6); 
    printf("%d",a);
    return 0;
}   
