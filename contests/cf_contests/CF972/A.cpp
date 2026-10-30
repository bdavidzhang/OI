#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m>>q;
        int a,b,c;
        cin >> a >> b >> c;
        long long res =0;

        int t = b;
        b = max(a,t);
        a = min(a,t);

        if (c > a && c < b){
            int d = (b-a)/2;
            b -= d*2;
            res += d;
            res += min(c-a,b-c); 
        }else if(c > b){
            int d = n-c;
            res += d;
            b += d;
            res += (n-b);
        }else if( c < a){
            int d = c -1;
            res += d;
            a -= d;
            res += (a - 1); 
        }
        cout << res << endl;
    }
    return 0;



}
