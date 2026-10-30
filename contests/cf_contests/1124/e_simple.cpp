#include <bits/stdc++.h>
using namespace std;

const int BITS = 18;
const int INF = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> nearest(1 << BITS, INF);
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		int n;
		cin >> n;
		vector<int> a(n), prefix(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			prefix[i + 1] = prefix[i] ^ a[i];
		}

		// a[k] is the (leftmost) max of a[l..r] iff left[k] <= l <= k <= r <= right[k]
		vector<int> left(n), right(n), stack;
		for (int i = 0; i < n; ++i) {
			while (!stack.empty() && a[stack.back()] < a[i]) stack.pop_back();
			left[i] = stack.empty() ? 0 : stack.back() + 1;
			stack.push_back(i);
		}
		stack.clear();
		for (int i = n - 1; i >= 0; --i) {
			while (!stack.empty() && a[stack.back()] <= a[i]) stack.pop_back();
			right[i] = stack.empty() ? n - 1 : stack.back() - 1;
			stack.push_back(i);
		}

		vector<int> key(n + 1), head(n + 1);
		vector<int> query_next, query_high, query_key;

		// Is there a segment (length >= 2) whose max and xor both contain every bit of s?
		auto check = [&](int s) {
			for (int x = 0; x <= n; ++x) key[x] = prefix[x] & s;
			fill(head.begin(), head.end(), -1);
			query_next.clear(), query_high.clear(), query_key.clear();
			// query: some position in [low, high] has key == k
			auto add = [&](int low, int high, int k) {
				if (low > high) return;
				query_next.push_back(head[low]);
				query_high.push_back(high);
				query_key.push_back(k);
				head[low] = static_cast<int>(query_key.size()) - 1;
			};

			// segment a[l..r] <-> prefix pair (l, r + 1); scan the smaller side of each max
			for (int k = 0; k < n; ++k) {
				if ((a[k] & s) != s) continue;
				int low = left[k], high = right[k] + 1;
				if (k - low <= high - k - 1) {
					for (int i = low; i <= k; ++i) add(i == k ? k + 2 : k + 1, high, key[i] ^ s);
				} else {
					for (int j = k + 1; j <= high; ++j) add(low, j == k + 1 ? k - 1 : k, key[j] ^ s);
				}
			}

			// answer all queries offline, sweeping low from right to left
			bool found = false;
			for (int pos = n; pos >= 0 && !found; --pos) {
				nearest[key[pos]] = pos;
				for (int q = head[pos]; q != -1; q = query_next[q]) {
					if (nearest[query_key[q]] <= query_high[q]) {
						found = true;
						break;
					}
				}
			}
			for (int x = 0; x <= n; ++x) nearest[key[x]] = INF;
			return found;
		};

		int answer = 0;
		for (int bit = BITS - 1; bit >= 0; --bit) {
			if (check(answer | 1 << bit)) answer |= 1 << bit;
		}
		cout << answer << '\n';
	}
}
