#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
typedef unsigned long long ull;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
#define pii pair<int, int>

ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool _isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
const int LIM = 1e6;
bitset<LIM> isPrime;
vi eratosthenes() {
	const int S = 1000, R = LIM / 2;
	vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
		cp.push_back({i, i * i / 2});
		for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
	}
	for (int L = 1; L <= R; L += S) {
		array<bool, S> block{};
		for (auto &[p, idx] : cp)
			for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
		rep(i,0,min(S, R - L))
			if (!block[i]) pr.push_back((L + i) * 2 + 1);
	}
	for (int i : pr) isPrime[i] = 1;
	return pr;
}

vi pr;
bool is_square_free(ull x){
  for(int & p : pr){
    ull q = p;
    if(x % (q*q) == 0) return false;
    else if(x % q == 0) x /= q;
  }
//   cout << x << endl;
  if(x == 1) return true;
//   cout << sqrt(x) << endl;
  ll root = round(sqrt(x));
  if(root*root == x) return false;
  return true;
}
ull A,B;
signed main(){
    pr = eratosthenes();
    cin >> A >> B;
    if(_isPrime(A) && _isPrime(B) && A != B){
        cout << "full credit" << endl;
        return 0;
    }
    else if(gcd(A,B) == 1 && is_square_free(A) && is_square_free(B)){
        cout << "partial credit" << endl;
    }else{
        cout << "no credit" << endl;
    }

    return 0;
}