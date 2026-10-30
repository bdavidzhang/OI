#include<bits/stdc++.h>
using namespace std;

void printInt128(__int128 value){
    if(value == 0){
        cout << 0;
        return;
    }
    if(value < 0){
        cout << '-';
        value = -value;
    }
    string digits;
    while(value > 0){
        digits += char('0' + value % 10);
        value /= 10;
    }
    reverse(digits.begin(), digits.end());
    cout << digits;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x,y,k;
        cin >> x >> y >> k;
        long long d = y - x;
        long long right = x + k - 1;
        __int128 res = 0;

        for(long long left = x; left <= right;){
            long long q = d / left;
            long long end = right;
            if(q > 0){
                end = min(end, d / q);
            }
            __int128 cnt = end - left + 1;
            res += cnt * d - (__int128)q * (left + end) * cnt / 2;
            left = end + 1;
        }
        printInt128(res);
        cout << '\n';
    }
    return 0;
}