#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;
    
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    void build(vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        long long left_gcd = query(2 * node, start, mid, l, r);
        long long right_gcd = query(2 * node + 1, mid + 1, end, l, r);
        if (left_gcd == 0) return right_gcd;
        if (right_gcd == 0) return left_gcd;
        return gcd(left_gcd, right_gcd);
    }
    
public:
    SegmentTree(vector<long long>& diff) {
        n = diff.size();
        tree.resize(4 * n);
        if (n > 0) {
            build(diff, 1, 0, n - 1);
        }
    }
    
    long long query(int l, int r) {
        if (n == 0 || l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Create difference array
        vector<long long> diff(n - 1);
        for (int i = 0; i < n - 1; i++) {
            diff[i] = abs(a[i + 1] - a[i]);
        }
        
        SegmentTree st(diff);
        
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--; r--; // Convert to 0-indexed
            
            if (i < q-1){
                if (l == r) {
                    cout << 0 << " ";
                } else {
                    cout << st.query(l, r - 1) << " ";
                }
            }else{
                if (l == r) {
                    cout << 0;
                } else {
                    cout << st.query(l, r - 1);
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}