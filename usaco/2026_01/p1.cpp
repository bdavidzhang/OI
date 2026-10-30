#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve_query() {
    int type;
    ll val, t;
    if (!(cin >> type >> val >> t)) return;

    if (type == 1) {
        ll c = val;
        ll cur_t = c;
        ll pos = c;

        while (cur_t < t) {
            ll next_t = cur_t + 1;
            ll limit = next_t / 2;

            if (pos == 0) {
                pos = limit;
                cur_t = next_t;
            } 
            else if (pos <= limit) {
                ll dist = pos;
                if (cur_t + dist <= t) {
                    cur_t += dist;
                    pos = 0;
                } else {
                    ll remain = t - cur_t;
                    pos -= remain;
                    cur_t = t;
                }
            } 
            else {
                ll target_t = 2 * pos - 1;

                if (target_t > t) {
                    cur_t = t; 
                } else if (target_t > cur_t) {
                    cur_t = target_t; 
                } else {
                    cur_t++; 
                }
            }
        }
        cout << pos << "\n";
    } 
    else {
        ll cur_t = t;
        ll pos = val;

        while (cur_t > 0) {
            ll limit = cur_t / 2;

            if (pos > limit) {
                break;
            } 
            else if (pos == limit) {
                pos = 0;
                cur_t--;
            } 
            else {
                ll k = (cur_t - 2 * pos) / 3;

                if (k == 0) {
                    pos++;
                    cur_t--;
                } else {
                    pos += k;
                    cur_t -= k;
                }
            }
        }
        cout << pos << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (cin >> Q) {
        while (Q--) {
            solve_query();
        }
    }
    return 0;
}