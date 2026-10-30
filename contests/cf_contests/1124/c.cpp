#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int k, const vector<long long>& values) {
	if (n < 2 * k - 1) {
		long long ans = 0;
		for (int mov = 0; mov <= n - k; ++mov) {
			ans += max(values[k - 1 + mov], values[n - k - mov]);
		}
		return ans;
	}

	int ops = n - 2 * k + 2;
	vector<long long> left_val(ops + 1, 0);
	vector<long long> right_val(ops + 1, 0);

	for (int cnt = 0; cnt < ops; ++cnt) {
		left_val[cnt + 1] = left_val[cnt] + values[k - 1 + cnt];
		right_val[cnt + 1] = right_val[cnt] + values[n - k - cnt];
	}

	long long ans = 0;
	for (int left_mov = 0; left_mov <= ops; ++left_mov) {
		int right_mov = ops - left_mov;
		ans = max(ans, left_val[left_mov] + right_val[right_mov]);
	}

	for (int mov = 0; mov < k - 1; ++mov) {
		ans += max(values[k - 2 - mov], values[n - k + 1 + mov]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<long long> values(n);
		for (long long& value : values) {
			cin >> value;
		}
		cout << solve(n, k, values) << '\n';
	}
}
