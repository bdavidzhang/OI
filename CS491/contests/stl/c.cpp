#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
using pii = pair<int,int>;
using vb = vector<bool>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second
#define mp make_pair
#define pb push_back



/** A data structure that can answer point update & range max queries. */
template <class T> class MaxSegmentTree {
  private:
    const T DEFAULT = std::numeric_limits<T>().lowest();  // Changed to lowest
    int len;
    vector<T> segtree;  // index 0 is not in use
    
    T combine(const T &a, const T &b) { return std::max(a, b); }  // Changed to max
    
    void build(const vector<T> &arr, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = arr[at_left];
            return;
        }
        int mid = (at_left + at_right) / 2;
        build(arr, 2 * at, at_left, mid);
        build(arr, 2 * at + 1, mid + 1, at_right);
        segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
    }

    void set(int ind, T val, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = val;
            return;
        }
        int mid = (at_left + at_right) / 2;
        if (ind <= mid) {
            set(ind, val, 2 * at, at_left, mid);
        } else {
            set(ind, val, 2 * at + 1, mid + 1, at_right);
        }
        segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
    }

    T range_max(int start, int end, int at, int at_left, int at_right) {  // Renamed to range_max
        if (at_right < start || end < at_left) { return DEFAULT; }
        if (start <= at_left && at_right <= end) { return segtree[at]; }
        int mid = (at_left + at_right) / 2;
        T left_res = range_max(start, end, 2 * at, at_left, mid);
        T right_res = range_max(start, end, 2 * at + 1, mid + 1, at_right);
        return combine(left_res, right_res);
    }

  public:
    MaxSegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, DEFAULT); };
    
    MaxSegmentTree(const vector<T> &arr) : len(arr.size()) {
        segtree = vector<T>(len * 4, DEFAULT);
        build(arr, 1, 0, len - 1);
    }

    /** Sets the value at ind to val. */
    void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

    /** @return the maximum element in the range [start, end] */
    T range_max(int start, int end) { return range_max(start, end, 1, 0, len - 1); }
};


void solve(){
    int n, m;
    cin >> n >> m;

    vi v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    
    MaxSegmentTree<int> MST = MaxSegmentTree(v);

    for(int i = 0;i < m; ++i){
        int a,b;
        cin >> a >>b;
        cout << MST.range_max(a-1,b-1) << endl;
    }


}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tk = 1;
    //cin >> tk;
    for(int i = 0; i < tk; ++i){
        solve();
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
