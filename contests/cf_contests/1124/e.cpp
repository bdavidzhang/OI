#include <bits/stdc++.h>
using namespace std;

const int BITS = 18;
const int INF = INT_MAX;

vector<int> nearest(1 << BITS, INF);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
    int n;
    cin >> n; 
    vector<int> a(n), pref(n+1,0);
    for (int i = 0 ;i < n; ++i){
      cin >> a[i];
      pref[i+1] = pref[i] ^ a[i];
    }

    vector<int> left(n), right(n), stack;
    for (int i = 0; i < n; ++i){
      while(!stack.empty() && a[stack.back()] < a[i]) stack.pop_back();
      left[i] = stack.empty() ? 0 : stack.back() + 1;
      stack.push_back(i);
    }
    stack.clear();
    for (int i = n-1; i >= 0; --i){
      while(!stack.empty() && a[stack.back()] < a[i]) stack.pop_back();
      left[i] = stack.empty() ? 0 : stack.back() + 1;
      stack.push_back(i);
    }

    vector<int> key(n+1), head(n+1);
    vector<int> q_next, q_high, q_key; 

    auto check = [&](int s) {
			for (int x = 0; x <= n; ++x) key[x] = pref[x] & s;
			fill(head.begin(), head.end(), -1);
			q_next.clear(), q_high.clear(), q_key.clear();
			auto add = [&](int low, int high, int k) {
				if (low > high) return;
				q_next.push_back(head[low]);
				q_high.push_back(high);
				q_key.push_back(k);
				head[low] = static_cast<int>(q_key.size()) - 1;
			};

			for (int k = 0; k < n; ++k) {
				if ((a[k] & s) != s) continue;
				int low = left[k], high = right[k] + 1;
				if (k - low <= high - k - 1) {
					for (int i = low; i <= k; ++i) add(i == k ? k + 2 : k + 1, high, key[i] ^ s);
				} else {
					for (int j = k + 1; j <= high; ++j) add(low, j == k + 1 ? k - 1 : k, key[j] ^ s);
				}
			}

			bool found = false;
			for (int pos = n; pos >= 0 && !found; --pos) {
				nearest[key[pos]] = pos;
				for (int q = head[pos]; q != -1; q = q_next[q]) {
					if (nearest[q_key[q]] <= q_high[q]) {
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

		cout << '\n';
	}
}
