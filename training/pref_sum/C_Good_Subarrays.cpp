#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long res = 0, tot = 0;
        map<int,int> d;
        d[0] = 1; //there is 1 empty sequence

        for(int i = 0; i < n; ++i){
            tot += int(s[i] - '0');
            int x = tot - i - 1;
            d[x]++;
            res += d[x] - 1;
        }
        cout << res << endl;
    }

    return 0;

}