
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const ll MOD = 1e9 + 7;

// 2x2 matrix
struct Mat {
    ll a[2][2] = {};

    static Mat identity() {
        Mat res;
        res.a[0][0] = res.a[1][1] = 1;
        return res;
    }
};

Mat operator*(const Mat& A, const Mat& B) {
    Mat C;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                C.a[i][j] = (C.a[i][j]
                    + A.a[i][k] * B.a[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Iterative segment tree for matrix products
struct SegTree {
    int n;
    vector<Mat> tr;

    SegTree(const vector<Mat>& a) {
        n = 1;
        while (n < (int)a.size()) n <<= 1;

        tr.assign(2 * n, Mat::identity());

        for (int i = 0; i < (int)a.size(); ++i)
            tr[n + i] = a[i];

        for (int i = n - 1; i >= 1; --i)
            tr[i] = tr[i << 1] * tr[i << 1 | 1];
    }

    // Point assignment
    void set(int pos, Mat val) {
        pos += n;
        tr[pos] = val;

        for (pos >>= 1; pos; pos >>= 1)
            tr[pos] = tr[pos << 1] * tr[pos << 1 | 1];
    }

    // Product over [l, r)
    Mat query(int l, int r) {
        Mat left = Mat::identity();
        Mat right = Mat::identity();

        l += n;
        r += n;

        while (l < r) {
            if (l & 1)
                left = left * tr[l++];

            if (r & 1)
                right = tr[--r] * right;

            l >>= 1;
            r >>= 1;
        }

        return left * right;
    }
};

void solve() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    // A[i] = {b, a}
    // b = number of optional elements (original 0s)
    // a = number of mandatory elements (original 1s)
    vector<pii> A(2 * N, {0, 0});

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1')
            A[N + i] = {0, 1};
        else
            A[N + i] = {1, 0};
    }

    // Precompute powers of 2
    vector<ll> pw(N + 1, 1);
    for (int i = 1; i <= N; ++i)
        pw[i] = pw[i - 1] * 2 % MOD;

    // Construct the transition matrix for one group
    auto segf = [&](int i) -> Mat {
        auto [b, a] = A[i];

        ll total = pw[b];
        ll present;

        if (a > 0)
            present = total;
        else
            present = (total - 1 + MOD) % MOD;

        Mat M;
        M.a[0][0] = present;
        M.a[0][1] = present;
        M.a[1][1] = total;

        return M;
    };

    vector<Mat> init(2 * N);
    for (int i = 0; i < 2 * N; ++i)
        init[i] = segf(i);

    SegTree seg(init);

    ll ans = 0;

    // Current active interval: [L, R)
    int L = N;
    int R = 2 * N;

    // Decrease the modulus from N-1 to 1
    for (int mod = N - 1; mod >= 1; --mod) {

        // Merge groups that wrap around
        for (int K = mod - 1; K < R - L; ++K) {
            int a = L + K;
            int V = (K + 1) % mod;
            int b = (L - 1) + V;

            if (a == b) continue;

            A[b].first += A[a].first;
            A[b].second += A[a].second;

            A[a] = {0, 0};

            seg.set(a, segf(a));
            seg.set(b, segf(b));
        }

        // Shift the active interval left
        --L;
        R = L + mod;

        // Sum of MEX over all valid supersets
        Mat res = seg.query(L, R);
        ans = (ans + res.a[0][1]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}

