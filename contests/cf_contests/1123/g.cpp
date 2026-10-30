#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int MOD = 1000000007;

int64 mod_pow(int64 value, int64 exponent, int mod) {
	int64 result = 1;
	while (exponent > 0) {
		if (exponent & 1) {
			result = result * value % mod;
		}
		value = value * value % mod;
		exponent >>= 1;
	}
	return result;
}

template <int MODULUS, int ROOT>
void ntt(vector<int>& values, bool invert) {
	int n = static_cast<int>(values.size());
	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1) {
			j ^= bit;
		}
		j ^= bit;
		if (i < j) {
			swap(values[i], values[j]);
		}
	}
  static vector<int64> powers;
  for (int length = 2; length <= n; length <<= 1) {
    int half = length / 2;
    int64 root = mod_pow(ROOT, (MODULUS - 1) / length, MODULUS);
    if (invert) {
            root = mod_pow(root, MODULUS - 2, MODULUS);
    }
    powers.resize(half);
    powers[0] = 1;
    for (int k = 1; k < half; ++k) {
            powers[k] = powers[k - 1] * root % MODULUS;
    }
    for (int start = 0; start < n; start += length) {
      for (int offset = 0; offset < half; ++offset) {
        int left = values[start + offset];
        int right = static_cast<int>(values[start + offset + half] * powers[offset] % MODULUS);
        values[start + offset] = left + right < MODULUS ? left + right : left + right - MODULUS;
        values[start + offset + half] = left - right >= 0 ? left - right : left - right + MODULUS;
      }
    }
  }

	if (invert) {
		int64 inverse_n = mod_pow(n, MODULUS - 2, MODULUS);
		for (int& value : values) {
			value = static_cast<int>(value * inverse_n % MODULUS);
		}
	}
}

template <int MODULUS, int ROOT>
vector<int> convolution_mod(const vector<int>& left, const vector<int>& right) {
	if (left.empty() || right.empty()) {
		return {};
	}

	int result_size = static_cast<int>(left.size() + right.size() - 1);
	int transform_size = 1;
	while (transform_size < result_size) {
		transform_size <<= 1;
	}

	vector<int> a(transform_size), b(transform_size);
	for (int i = 0; i < static_cast<int>(left.size()); ++i) {
		a[i] = left[i] % MODULUS;
	}
	for (int i = 0; i < static_cast<int>(right.size()); ++i) {
		b[i] = right[i] % MODULUS;
	}

	ntt<MODULUS, ROOT>(a, false);
	ntt<MODULUS, ROOT>(b, false);
	for (int i = 0; i < transform_size; ++i) {
		a[i] = static_cast<int>(static_cast<int64>(a[i]) * b[i] % MODULUS);
	}
	ntt<MODULUS, ROOT>(a, true);
	a.resize(result_size);
	return a;
}

int64 normalize(int64 value, int64 modulus) {
	value %= modulus;
	if (value < 0) {
		value += modulus;
	}



	return value;
}

vector<int> convolution(const vector<int>& left, const vector<int>& right) {
  if (min(left.size(), right.size()) <= 64) {
    vector<int64> acc(left.size() + right.size() - 1, 0);
    for (int i = 0; i < static_cast<int>(left.size()); ++i) {
      for (int j = 0; j < static_cast<int>(right.size()); ++j) {
        acc[i + j] = (acc[i + j] + static_cast<int64>(left[i]) * right[j]) % MOD;
      }
    }
    return vector<int>(acc.begin(), acc.end());
  }
	const int p1 = 998244353;
	const int p2 = 1004535809;
	const int p3 = 469762049;

	vector<int> r1 = convolution_mod<p1, 3>(left, right);
	vector<int> r2 = convolution_mod<p2, 3>(left, right);
	vector<int> r3 = convolution_mod<p3, 3>(left, right);

	int64 inverse_p1_mod_p2 = mod_pow(p1 % p2, p2 - 2, p2);
	int64 p1p2_mod_p3 = static_cast<int64>(p1 % p3) * (p2 % p3) % p3;
	int64 inverse_p1p2_mod_p3 = mod_pow(p1p2_mod_p3, p3 - 2, p3);

	vector<int> result(r1.size());
	for (int i = 0; i < static_cast<int>(r1.size()); ++i) {
		int64 first_step = normalize(r2[i] - r1[i], p2);
    first_step = first_step * inverse_p1_mod_p2 % p2;
    int64 value12_mod_p3 = (r1[i] + static_cast<int64>(p1 % p3) * first_step) % p3;

    int64 second_step = normalize(r3[i] - value12_mod_p3, p3);
    second_step = second_step * inverse_p1p2_mod_p3 % p3;
    int64 p1p2_mod = static_cast<int64>(p1) * p2 % MOD;
    result[i] = static_cast<int>((r1[i] + static_cast<int64>(p1) * first_step % MOD + p1p2_mod * second_step) % MOD);
	}
	return result;
}
vector<int> inverse(const vector<int>& f, int n) {
      vector<int> g = {1};
      for (int len = 1; len < n; len *= 2) {
              int nl = min(2 * len, n);
              vector<int> fcut(f.begin(), f.begin() + min<size_t>(nl, f.size()));
              vector<int> e = convolution(fcut, g);  // f*g = 1 + O(x^len)
              e.resize(nl);
              for (int i = 0; i < len; ++i) e[i] = 0;  // keep only the error term
              vector<int> corr = convolution(e, g);  // g_new = g - g*(f*g - 1)
              g.resize(nl);
              for (int i = len; i < nl; ++i) g[i] = corr[i] ? MOD - corr[i] : 0;
      }
      return g;
}

int solve(int n, int mask, const vector<int>& values) {
      vector<int> one_minus_k(n + 1, 0), kernel_cost(n + 1, 0);
      one_minus_k[0] = 1;
      for (int step = 1; step <= n; ++step) {
              if ((mask & step) == step) {
                      one_minus_k[step] = MOD - 1;
                      kernel_cost[step] = values[step];
              }
      }
      vector<int> ways = inverse(one_minus_k, n + 1);  // ways = 1/(1-K)
      vector<int> ways_sq = convolution(ways, ways);
      int64 ans = 0;  // only [x^n] of W * ways^2 is needed, so a dot product suffices
      for (int i = 0; i <= n; ++i) ans = (ans + (int64)kernel_cost[i] * ways_sq[n - i]) % MOD;
      return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> cost(m + 1);
		for (int step = 1; step <= m; ++step) {
			int64 val;
			cin >> val;
			cost[step] = val % MOD;
		}

		cout << solve(n,m,cost) << endl;
	}
}
