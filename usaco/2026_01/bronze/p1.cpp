#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll A, B, cA, cB, fA;
    if (!(cin >> A >> B >> cA >> cB >> fA)) return;

    if (A >= fA) {
        cout << 0 << "\n";
        return;
    }

    ll low = 0, high = 4000000000000000000LL; 
    ll ans = high;

    while (low <= high) {
        ll x = low + (high - low) / 2;
       
        auto get_chips = [&](ll a) -> __int128 {
            __int128 total_A = A + a;
            __int128 total_B = B + x - a;
            __int128 converted_A = (total_B / cB) * cA;
            return total_A + converted_A;
        };

        __int128 min_chips = get_chips(0);

        
        ll a_target = -1;

        if (cA > cB) {
           
            ll rem_B = B % cB;
            ll target_rem = cB - 1;
            
            ll dist = (target_rem - rem_B + cB) % cB; 
            
            if (dist <= x) {
                a_target = x - dist;
            }
        } else {
            
            ll term = B + x;
            ll rem_term = term % cB;
            ll target_rem = cB - 1;
            
            ll dist = (rem_term - target_rem + cB) % cB;
            
            if (dist <= x) {
                a_target = dist;
            }
        }

        if (a_target != -1) {
            __int128 val = get_chips(a_target);
            if (val < min_chips) min_chips = val;
        }

        if (min_chips >= fA) {
            ans = x;
            high = x - 1;
        } else {
            low = x + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}