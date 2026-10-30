#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    
    vector<long long> a(3),b(3);
    for(int i = 0;i < 3; ++i){
        cin >> a[i]; 
    }
    for(int i = 0;i < 3; ++i){
        cin >> b[i]; 
    }
    long long tie = 0;
    for(int i = 0; i < 3; ++i){
        tie = max(tie, a[i] - b[i] - b[(i+2)%3]);
    } 
    long long win = 0;
    for(int i = 0 ;i < 3; ++i){
        win += min(a[i], b[(i+1)%3]);
        
    }
    cout << tie << " " << win << endl;
    
    return 0;

}

