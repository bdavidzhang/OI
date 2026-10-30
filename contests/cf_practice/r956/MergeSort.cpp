#include<iostream>

void Merge(int leftarr[], int rightarr[], int arr[], int len){
    int i = 0, l = 0, r = 0;
    int left = len/2;
    int right = len-left;
    while(l < left && r < right){
        if(leftarr[l] < rightarr[r]){
            arr[i] = leftarr[l];
            i++;
            l++;
        }
        else{
            arr[i] = rightarr[r];
            i++;
            r++;
        }
    }
    while (l < left){
        arr[i] = leftarr[l];
        i++;
        l++;
    }
    while (r < right){
        arr[i] = rightarr[r];
        i++;
        r++;
    }
} 



void MergeSort(int arr[],int len){
    if(len <= 1) return;
    int mid = len/2;
    int leftarr[mid];
    int rightarr[len-mid];
    int i = 0, j = 0;
    for (; i < len; ++i){
       if (i < mid){
           leftarr[i] = arr[i];
       }
       else {
           rightarr[j] = arr[i];
           j++;
       }
    } 
    MergeSort(leftarr,mid);
    MergeSort(rightarr,len-mid);
    Merge(leftarr,rightarr,arr,len);

} 


int main(){
    int arr[8] = {4,5,6,7,8,1,2,3};
    MergeSort(arr,8);
    for (auto x : arr) std::cout<<x<< ' ';
    std::cout<<'\n';
    return 0;
}

