#include<bits/stdc++.h>
using namespace std;

int cnt[3][3];
long long ans = 0;
int tot_p = 0, tot_q = 0;
int main(){
    
    cnt[0][0] = 1;
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        int cur_p = a % 3;
        int cur_q = (a % 3 == 0) ? 0 : 1;
        tot_p += cur_p;
        tot_q += cur_q;
        tot_p %= 3;
        tot_q %= 3;

        int p1 = tot_p;
        int q1 = tot_q;

        int p2 = (tot_p - 1 + 3) % 3;
        int q2 = (tot_q - 1 + 3) % 3;

        int p3 = (tot_p - 2 + 3) % 3;
        int q3 = (tot_q - 1 + 3) % 3; 

        ans += cnt[p1][q1] + cnt[p2][q2] + cnt[p3][q3];

        cnt[tot_p][tot_q]++;
        
    }
    cout << ans << endl;

}