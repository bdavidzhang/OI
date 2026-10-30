#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right.
 * Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */


struct Tree {
    struct Node{
        long long sum;
        int cnt;
    };
    typedef Node T;
	static constexpr T unit = {0,0};
	T f(const T& a, const T& b) {
        return {a.sum+b.sum,a.cnt+b.cnt};
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};





int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,k;
    cin >> n >> k;
    vi a(n),b(n);
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a[i] = x - k;
    }
    for(int i = 0 ;i < n; ++i){
        cin >> b[i];
    }

    vector<int> costs;
    costs.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) costs.push_back(-a[i]);
    }
    sort(all(costs));
    costs.erase(unique(all(costs)), costs.end());

    auto get_id = [&](int cost) {
        return int(lower_bound(all(costs), cost) - costs.begin());
    };

    long long pos_sum = 0;
    int pos_cnt = 0;
    int maxlen = 0;
    Tree segtree(sz(costs));

    auto apply = [&](int i, int delta) {
        if (a[i] >= 0) {
            pos_sum += 1LL * delta * a[i];
            pos_cnt += delta;
            return;
        }
        int cost = -a[i];
        int id = get_id(cost);
        auto cur = segtree.query(id, id + 1);
        cur.sum += 1LL * delta * cost;
        cur.cnt += delta;
        segtree.update(id, cur);
    };

   auto eval = [&]() {
        int take_neg = 0;
        int m = sz(costs);
        if (m > 0 && pos_sum > 0) {
            int lo = 0, hi = m - 1, best = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (segtree.query(0, mid + 1).sum <= pos_sum) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            long long current_sum = 0;
            // Take all elements from fully affordable buckets
            if (best != -1) {
                auto res = segtree.query(0, best + 1);
                take_neg += res.cnt;
                current_sum = res.sum;
            }
            
            // Greedily take elements from the next partially affordable bucket
            int next_id = best + 1;
            if (next_id < m) {
                long long rem_budget = pos_sum - current_sum;
                long long cost_per_item = costs[next_id];
                long long can_afford = rem_budget / cost_per_item;
                long long available = segtree.query(next_id, next_id + 1).cnt;
                
                take_neg += min(available, can_afford);
            }
        }
        maxlen = max(maxlen, pos_cnt + take_neg);
    };

    //preprocess all 2s
    for(int i = 0; i < n; ++i){
        if(b[i] == 2){
            apply(i, +1);
        }
    }
    eval();

    //now the more general case, index starts to move
    for(int i = 0; i < n; ++i){
        if(b[i] == 1){
            apply(i, +1);
        }else{
            apply(i, -1);
        }
        eval();
    }

    cout << maxlen << '\n';
}