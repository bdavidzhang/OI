#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


/**
 * Author: Jakob Kogler, chilli, pajenegod
 * Date: 2020-04-12
 * License: CC0
 * Description: Prime sieve for generating all primes smaller than LIM.
 * Time: LIM=1e9 $\approx$ 1.5s
 * Status: Stress-tested
 * Details: Despite its n log log n complexity, segmented sieve is still faster
 * than other options, including bitset sieves and linear sieves. This is
 * primarily due to its low memory usage, which reduces cache misses. This
 * implementation skips even numbers.
 *
 * Benchmark can be found here: https://ideone.com/e7TbX4
 *
 * The line `for (int i=idx; i<S+L; idx = (i += p))` is done on purpose for performance reasons.
 * Se https://github.com/kth-competitive-programming/kactl/pull/166#discussion_r408354338
 */

const int LIM = 1e6;
bitset<LIM> isPrime;
vi eratosthenes() {
	const int S = (int)round(sqrt(LIM)), R = LIM / 2;
	vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
		cp.push_back({i, i * i / 2});
		for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
	}
	for (int L = 1; L <= R; L += S) {
        vector<char> block((size_t)S, false);

        for (auto& [p, idx] : cp)
            for (int i = idx; i < S + L; idx = (i += p))
                block[(size_t)(i - L)] = true;

        for (int i = 0; i < min(S, R - L); i++)
            if (!block[(size_t)i])
                pr.push_back((L + i) * 2 + 1);
    }

    for (int x : pr) isPrime[(size_t)x] = 1;

    return pr;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    vi primes = eratosthenes();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cout << primes[i]*primes[i+1] << " ";
        }
        cout << endl;
    }

    // vector<int> v = vector<int>(10,0);
}
