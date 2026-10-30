//equalizing two strings,basically problem D
#include<unordered_set>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int merge(int arr[], int leftarr[], int rightarr[], int size){
    int l = 0, r = 0, i = 0, inv_cnt = 0;
    int left = size/2;
    int right = size-left;
    while(l < left && r < right){
        if (leftarr[l] < rightarr[r]){
            arr[i] = leftarr[l];
            l++;
        }else{
            inv_cnt += left-l;
            arr[i] = rightarr[r];
            r++;
        }
        i++;
    }
    while (l < left){
        arr[i] = leftarr[l];
        l++;
        i++;
    }
    while (r < right){
        arr[i] = rightarr[r];
        r++;
        i++;
    }
    return inv_cnt;
}



int invcnt(int arr[], int size){
    int inv_cnt = 0;
    if(size <= 1) return 0;
    int mid = size /2;
    int leftarr[mid],rightarr[size-mid];
    int i = 0, j = 0;
    for (; i < size; ++i){ 
        if (i < mid){
            leftarr[i] = arr[i];
        }else{
            rightarr[j] = arr[i];
            j++;
        }
    }
    inv_cnt += invcnt(leftarr,mid);
    inv_cnt += invcnt(rightarr,size-mid);
    inv_cnt += merge(arr,leftarr,rightarr,size);
    return inv_cnt;
}

        





void solve(){
    int n;
    std::cin>>n;
    std::string s,t;
    std::cin>>s>>t;
    //copy strings
    std::vector<int> a(n),b(n);
    int c[n],d[n];
    
    for (int i = 0; i < n; ++i){
        a[i] = s[i] - 'a';
        b[i] = t[i] - 'a';
        c[i] = a[i];
        d[i] = b[i];
    } 
    
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());
    for (int i = 0; i < n; ++i){
       if(a[i] != b[i]){
            std::cout<<"NO"<<'\n';
            return;
       } 
    }
    std::unordered_set<int> seen; 
    
    //if there are duplicates, you can change the parity, thus always making it valid
    for (int i = 0; i < n; ++i){
        if(seen.find(a[i]) != seen.end()){
            std::cout<<"YES"<<'\n';
            return;
        }
        seen.insert(a[i]);
    }
    

    if (invcnt(c,n) % 2 == invcnt(d,n) % 2){
        std::cout<<"YES"<<'\n';
        return;
    }else{
        std::cout<<"NO"<<'\n';
        return;
    }
}
    

    

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin>>q;
    while (q--){
        solve();

    }
    return 0;
}
