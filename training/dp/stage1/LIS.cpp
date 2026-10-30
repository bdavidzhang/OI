//longest increasing sequence
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int n;
int A[maxn];

int solve(int i, int prev){
    if(i > n) return 0;
    if(i == n && A[i-1] > prev) return 1;
    if(i == n) return 0;
    int best = 0;
    for(int j = i; j <= n; ++j)
        if(A[j-1] > prev) 
            best = max(best,1+solve(j+1,A[j-1]));
    
    return best;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> A[i]; 
    cout << solve(1,-1) << endl; 

    return 0;
}