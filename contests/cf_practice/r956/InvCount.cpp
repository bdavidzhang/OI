#include<iostream>




int Merge(int leftarr[], int rightarr[], int arr[], int size);

int InvCount(int arr[], int size){
    int invcount = 0;
    if (size > 1){
        int mid = size/2;
        
        int leftarr[mid];
        int rightarr[size-mid];

        int i = 0, j = 0;
        for (; i < size; ++i){
            if ( i < mid){
                leftarr[i] = arr[i];
            }else{
                rightarr[j] = arr[i];
                j++;
            }

        }
        invcount += InvCount(leftarr,mid);
        invcount += InvCount(rightarr,size-mid);
        invcount += Merge(leftarr,rightarr,arr,size);

    } 

    return invcount;
}


int Merge(int leftarr[], int rightarr[], int arr[], int size){
    int invcount = 0;
    int left = size / 2;
    int right = size - left;
    int i = 0, l = 0, r= 0;
    while(l < left && r < right){
        if (leftarr[l] < rightarr[r]){
            arr[i] = leftarr[l];
            i++;
            l++;
        }
        else{
            arr[i] = rightarr[r];
            invcount += left - l; 
            r++;
            i++;
        }
    }
    while( l < left){
        arr[i] = leftarr[l];
        l++;
        i++;
    }
    while (r < right){
        arr[i] = rightarr[r];
        r++;
        i++;
    }
    return invcount;
}


int main(){
    int arr[] = {1,6,2,3,4,5};

    std::cout<< InvCount(arr,6) << '\n';

    for (auto x : arr) std::cout<<x<<' ';
    std::cout<<"\n";
    return 0;
}


