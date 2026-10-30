#include<bits/stdc++.h>
using namespace std;


int n;
const int maxN = 2e5;
const int maxLog = 20;
int table[maxN][maxLog], a[maxN];

int gcd(int a, int b){
    if(b > a) return gcd(b,a);
    if(b == 0) return a;
    return gcd(b, a % b);
}

void precalc(){
    for(int st = 0; (1<<st) <= n; ++st){
        for(int i = 0; i <= n - (1 << st); ++i){
            if(st == 0){
                table[i][st] = a[i];
                continue;
            }
            table[i][st] = gcd(table[i][st-1],table[i+(1<<(st-1))][st-1]);
        }
    }
}

int getGCD(int l, int r){
    int st = int(log2(r-l+1));
    return gcd(table[l][st],table[r+1-(1<<st)][st]);
}


int main(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    precalc(); 
    int ans = 0;
    int maxR = -1;
    int pt = 0;
    for(int i = 0; i < n; ++i){
        while(pt < i && getGCD(pt,i) < i-pt+1) ++pt;
        if(getGCD(pt,i) == i-pt+1){
            if(pt > maxR){
                ans++;
                maxR = i;
            }
        }
        cout << ans << " ";
    }
}