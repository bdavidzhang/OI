#include<bits/stdc++.h>
using namespace std;

const int maxn = 200;
int x[maxn], y[maxn];

int dist(int a,int b, int c, int d){
    return abs(a - c) + abs(b - d);
}

void solve(){
        int n, k;
        cin >> n >> k;
        for(int i= 0 ;i < n; ++i) cin >> x[i] >> y[i];
        for(int i = 0; i < n; ++i){
            bool flag = true;
            for(int j = 0; j < n; ++j){
                if(dist(x[i],y[i],x[j],y[j]) > k){
                    flag = false;
                }
            }
            if(flag){
                cout << 1 << endl;
                return;
            }
        }

        cout << -1 << endl;

        
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}