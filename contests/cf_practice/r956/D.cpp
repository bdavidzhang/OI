#include<iostream>
#include<cstdio>
#include<algorithm>

int merge(int arr[], int leftarr[], int rightarr[], int size, int left, int right){
    int invcount = 0;
    int i = 0, l = 0, r = 0;
      
    while(l < left && r < right){
        if(leftarr[l] < rightarr[r]){
            arr[i] = leftarr[l];
            l++;
        }
        else{
            arr[i] = rightarr[r];
            invcount+=left-l;
            r++;
        }
        i++;
    }

    while(l < left){
        arr[i] = leftarr[l];
        i++;
        l++;
    }
    while(r < right){
        arr[i] = rightarr[r];
        i++;
        r++;
    }
    return invcount;   
}

int inversions(int arr[], int size){
    int inv_count = 0;
    if (size > 1){
        int mid = size/2; 
        int leftarr[mid],rightarr[size-mid];
        int i = 0, j = 0;
        for (; i < size; ++i){
            if( i < mid){
                leftarr[i] = arr[i];
            }
            else{
                rightarr[j] = arr[i];
                j++;
            }
        }
        inv_count += inversions(leftarr,mid);
        inv_count += inversions(rightarr,size-mid);
        inv_count += merge(arr,leftarr,rightarr,size,mid,size-mid);
    }
    return inv_count;
}




int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;    
    while(t--){
        int n;
        std::cin >> n;
        int a[n], b[n], x[n], y[n];
        for (int i =0; i < n; ++i){
            std::cin >> a[i];
            x[i] = a[i];
        }
        for (int i = 0; i< n; ++i){
            std::cin>> b[i];
            y[i] = b[i];
        }

        std::sort(x,x+n);
        std::sort(y,y+n);

        bool flag = true;
        for (int i =0; i < n; ++i){
            if (x[i] != y[i]) flag = false;
        }
        
        bool ok = false; 
        
        if (inversions(a,n) % 2 == inversions(b,n) %2) ok = true;

        

        if(ok && flag) std::cout<<"YES"<<'\n';
        else std::cout<<"NO"<<'\n';
    }

        
        


    return 0;
}
