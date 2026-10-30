#include <bits/stdc++.h>
using namespace std;

// Educational "complete-the-code" version of H.cpp
// Goal: understand the algorithm by implementing key parts yourself.
// Instructions:
// - Read the original fast solution in H.cpp for reference.
// - Complete the TODOs below. The file compiles and runs with
//   the provided naive (O(n) range) Tree implementation, but
//   you should replace it with the O(log N) segment-tree from
//   H.cpp as an exercise.

using ll = long long;
using vi = vector<int>;

// Node stores total cost sum and count of items in a bucket.
struct Node {
    ll sum = 0;
    int cnt = 0;
};

// ===== Naive Tree (exercise: replace with segment tree) =====
// This Tree is intentionally simple: update and query run in O(m)
// where m = number of distinct costs. It is correct but slow.
// TODO: Replace this implementation with the log-time segment tree
// from H.cpp when you are comfortable with the logic.
// struct Tree {
//     int n;
//     vector<Node> s;
//     Tree(int n_ = 0) { init(n_); }
//     void init(int n_) { n = n_; s.assign(n, Node()); }

//     // Update position pos to value val (overwrite)
//     void update(int pos, Node val) {
//         // naive: direct assign
//         if (pos < 0 || pos >= n) return;
//         s[pos] = val;
//     }

//     // Query range [b, e) and return aggregated Node
//     Node query(int b, int e) {
//         Node res;
//         if (b < 0) b = 0;
//         if (e > n) e = n;
//         for (int i = b; i < e; ++i) {
//             res.sum += s[i].sum;
//             res.cnt += s[i].cnt;
//         }
//         return res;
//     }
// };

struct Tree {
	typedef Node T;
    static inline constexpr T unit = {0,0};
	T f(T a, T b) { return {a.sum+b.sum,a.cnt+b.cnt}; } // (any associative fn)
	vector<T> s; int n;
    void init(int n_=0){
        n = n_;
        s = vector<T>(2*n_,unit);
    }
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



// ===== Algorithm helpers to complete =====
// You'll implement:
//  - get_id(costs, cost): map cost -> index in costs vector
//  - apply(i, delta): add/remove element i from current window
//  - eval(): compute how many negative-cost items can be paired
// The scaffolding below contains hints and a working naive
// implementation you can study and then reimplement yourself.

int n, K;
vi a, b;
vector<int> costs; // distinct positive costs (=-a[i] for a[i]<0)
Tree seg;
ll pos_sum = 0; // sum of positive a[i] included
int pos_cnt = 0; // count of positive a[i] included
int maxlen = 0;

inline int get_id(int cost) {
    // returns index of cost in sorted unique costs
    return int(lower_bound(costs.begin(), costs.end(), cost) - costs.begin());
}

// apply: include (delta=+1) or remove (delta=-1) element i
// Hint: if a[i] >= 0, it contributes to pos_sum and pos_cnt.
// Otherwise it belongs to a cost bucket indexed by get_id(-a[i]).
void apply(int i, int delta) {
    if (a[i] >= 0) {
        pos_sum += 1LL * delta * a[i];
        pos_cnt += delta;
        return;
    }
    int cost = -a[i];
    int id = get_id(cost);
    Node cur = seg.query(id, id + 1);
    cur.sum += 1LL * delta * cost;
    cur.cnt += delta;
    seg.update(id, cur);
}

// eval: compute number of negative-cost items we can "buy"
// using budget pos_sum. We greedily take from cheapest buckets.
// This is implemented with naive queries; later replace with
// log-time prefix queries over the segment tree.
void eval() {
    int take_neg = 0;
    int m = (int)costs.size();
    if (m > 0 && pos_sum > 0) {
        // Find the largest full prefix we can afford.
        // Naive approach: linear scan to accumulate sums.
        int lo = 0, hi = m - 1, best = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (seg.query(0, mid + 1).sum <= pos_sum) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        ll cur_sum = 0;
        // take all items from fully affordable buckets
        if (best != -1) {
            Node res = seg.query(0, best + 1);
            take_neg += res.cnt;
            cur_sum = res.sum;
        }

        // From the next bucket take as many as budget allows
        int next_id = best + 1;
        if (next_id < m) {
            ll rem = pos_sum - cur_sum;
            ll c = costs[next_id];
            Node bucket = seg.query(next_id, next_id + 1);
            ll can = rem / c;
            take_neg += (int)min<ll>(bucket.cnt, can);
        }
    }
    maxlen = max(maxlen, pos_cnt + take_neg);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input: n and K, then arrays A and B
    if (!(cin >> n >> K)) return 0;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; a[i] = x - K; }
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Build list of distinct positive costs (for negative a[i])
    costs.clear();
    for (int i = 0; i < n; ++i) if (a[i] < 0) costs.push_back(-a[i]);
    sort(costs.begin(), costs.end());
    costs.erase(unique(costs.begin(), costs.end()), costs.end());

    seg.init((int)costs.size());

    // Preprocess: add all b[i]==2 into the window first
    for (int i = 0; i < n; ++i) {
        if (b[i] == 2) apply(i, +1);
    }
    eval();

    // Slide index: at each i we add b[i]==1 and remove b[i]==2
    for (int i = 0; i < n; ++i) {
        if (b[i] == 1) apply(i, +1);
        else apply(i, -1);
        eval();
    }

    cout << maxlen << '\n';
    return 0;
}

/*
Tasks for you (in order):
- Study this naive Tree and understand how update/query work.
- Replace Tree with the segment-tree used in H.cpp (log N operations):
  - implement Node f(a,b) combining two nodes
  - implement update(pos,val) and query(b,e) using the iterative segtree
- Optimize eval(): instead of linear prefix scan, perform binary search
  on prefix sums using seg.query(0, mid+1).sum to find 'best' index.
- After you implement the segment tree, test and compare speed on
  large random inputs.

Hints:
- In the segtree, store at each index the sum of costs and count.
- To find how many items you can take from a partially affordable
  bucket, compute remaining budget and divide by the bucket cost.
*/
