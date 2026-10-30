# 基础模版

Everything else in the notebook assumes this header. Type it first in a contest.

## 文件头

```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
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

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7; // or 998244353
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}; // right, up, left, down

void solve(){

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
```

- no test count, read until EOF: `while(cin >> n) solve(n);`
- big output: use `"\n"`, not `endl` (`endl` flushes every line)
- doubles: `cout << fixed << setprecision(10) << ans << "\n";`
- optional, above `#include`: `#pragma GCC optimize("O3,unroll-loops")`

## 调试

Put right under the header. Only prints when compiled with `-DLOCAL`, so it's safe to submit.

```cpp
#ifdef LOCAL
template<class T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < sz(v); ++i) os << (i ? ", " : "") << v[i];
    return os << "}";
}
template<class A, class B> ostream& operator<<(ostream& os, pair<A, B> p) {
    return os << "(" << p.fi << ", " << p.se << ")";
}
void _dbg() { cerr << endl; }
template<class T, class... U> void _dbg(T a, U... b) {
    cerr << a << (sizeof...(b) ? ", " : "");
    _dbg(b...);
}
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "] = ", _dbg(__VA_ARGS__)
#else
#define dbg(...)
#endif
// dbg(n, v, p); -> [n, v, p] = 3, {1, 2, 3}, (4, 5)
```

## 编译 & 对拍

```bash
g++ -std=c++17 -O2 -Wall -Wextra -DLOCAL a.cpp -o a
# hunting a crash / out of bounds:
g++ -std=c++17 -g -DLOCAL -D_GLIBCXX_DEBUG -fsanitize=address,undefined a.cpp -o a
```

Stress test: `gen.cpp` prints a random test from a seed, `brute.cpp` is the slow sure answer.

```cpp
// gen.cpp
int main(int argc, char* argv[]) {
    mt19937 rng(atoi(argv[1]));
    auto rnd = [&](int l, int r) { return uniform_int_distribution<int>(l, r)(rng); };
    int n = rnd(1, 10);
    cout << n << "\n";
    for (int i = 0; i < n; ++i) cout << rnd(1, 100) << " \n"[i == n - 1];
}
```

```bash
# run.sh
g++ -O2 a.cpp -o a && g++ -O2 brute.cpp -o brute && g++ -O2 gen.cpp -o gen || exit
for ((i = 1; ; ++i)); do
    ./gen $i > in
    ./a < in > out1
    ./brute < in > out2
    if ! cmp -s out1 out2; then echo "diff on seed $i"; cat in; break; fi
done
```

## 常用小函数

```cpp
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); } // [l, r]
// shuffle(all(v), rng);

ll fdiv(ll a, ll b) { return a / b - ((a % b != 0) && ((a < 0) != (b < 0))); } // floor(a / b)
ll cdiv(ll a, ll b) { return a / b + ((a % b != 0) && ((a < 0) == (b < 0))); } // ceil(a / b)

ll power(ll a, ll b, ll m = MOD) { // a^b mod m, b >= 0
    ll r = 1;
    a = (a % m + m) % m;
    while(b) {
        if(b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}
// inverse when m is prime: power(a, m - 2)

void print(__int128 x) { // cout can't print __int128
    if(x < 0) { cout << '-'; x = -x; }
    if(x > 9) print(x / 10);
    cout << char('0' + x % 10);
}

struct chash { // unordered_map<ll, int, chash> M; stops anti-hash tests on CF
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t R = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + R);
    }
};
```

Coordinate compression:

```cpp
vi xs = a;
sort(all(xs));
xs.erase(unique(all(xs)), xs.end());
for (int i = 0; i < n; ++i) a[i] = lower_bound(all(xs), a[i]) - xs.begin(); // now 0..sz(xs)-1
```

## STL 小抄

- `__builtin_popcountll(x)` set bits, `__builtin_ctzll(x)` trailing zeros, `__lg(x)` = floor(log2 x)
- `1LL << k`, not `1 << k`, once k can reach 31
- `accumulate(all(v), 0LL)`: with plain `0` the sum is an `int` and overflows
- `gcd(a, b)`, `lcm(a, b)` (C++17); `lcm` can overflow, use `a / gcd(a, b) * b`
- `iota(all(v), 0)` fills 0, 1, 2, ...
- `lower_bound` first `>= x`, `upper_bound` first `> x`; on a `set` call `s.lower_bound(x)`, not `lower_bound(all(s), x)` (that one is O(n))
- min-heap: `priority_queue<int, vi, greater<int>> pq;`
- `nth_element(v.begin(), v.begin() + k, v.end())` puts the k-th smallest at `v[k]` in O(n)
- `sort(all(v), greater<int>())` descending; `reverse(all(v))`
- `next_permutation(all(v))` steps through permutations; sort first to get all of them
- `ll` max is about 9.2e18, `int` max about 2.1e9
