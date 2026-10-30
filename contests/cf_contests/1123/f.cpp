#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
	int child[2] = {-1, -1};
	int count = 0;
};

struct State {
	int value;
	int first;
	int second;
	int bit;

	bool operator>(const State& other) const {
		return value > other.value;
	}
};

vector<int> transform(const vector<int>& values) {
	vector<TrieNode> trie(1);

	for (int value : values) {
		int node = 0;
		++trie[node].count;

		for (int bit = 29; bit >= 0; --bit) {
			int direction = (value >> bit) & 1;
			if (trie[node].child[direction] == -1) {
				trie[node].child[direction] = static_cast<int>(trie.size());
				trie.emplace_back();
			}
			node = trie[node].child[direction];
			++trie[node].count;
		}
	}

	priority_queue<State, vector<State>, greater<State>> states;
	states.push({0, 0, 0, 29});

	vector<int> result;
	result.reserve(values.size());

	while (!states.empty() && result.size() < values.size()) {
		State current = states.top();
		states.pop();

		if (current.bit < 0) {
			long long pairs;
			if (current.first == current.second) {
				long long count = trie[current.first].count;
				pairs = count * (count - 1) / 2;
			} else {
				pairs = 1LL * trie[current.first].count * trie[current.second].count;
			}

			long long remaining = values.size() - result.size();
			int take = static_cast<int>(min(pairs, remaining));
			result.insert(result.end(), take, current.value);
			continue;
		}

		int left_first = trie[current.first].child[0];
		int right_first = trie[current.first].child[1];
		int left_second = trie[current.second].child[0];
		int right_second = trie[current.second].child[1];

		if (current.first == current.second) {
			if (left_first != -1) {
				states.push({current.value, left_first, left_first, current.bit - 1});
			}
			if (right_first != -1) {
				states.push({current.value, right_first, right_first, current.bit - 1});
			}
			if (left_first != -1 && right_first != -1) {
				states.push({
					current.value | (1 << current.bit),
					left_first,
					right_first,
					current.bit - 1,
				});
			}
		} else {
			int first_children[2] = {left_first, right_first};
			int second_children[2] = {left_second, right_second};

			for (int first_bit = 0; first_bit < 2; ++first_bit) {
				if (first_children[first_bit] == -1) {
					continue;
				}
				for (int second_bit = 0; second_bit < 2; ++second_bit) {
					if (second_children[second_bit] == -1) {
						continue;
					}

					int first = first_children[first_bit];
					int second = second_children[second_bit];
					if (first > second) {
						swap(first, second);
					}

					int next_value = current.value;
					if (first_bit != second_bit) {
						next_value |= 1 << current.bit;
					}
					states.push({next_value, first, second, current.bit - 1});
				}
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;

	while (tt--) {
		int n, q;
		cin >> n >> q;

		vector<int> cur(n);
		for (int& val : cur) {
			cin >> val;
		}

		vector<int> qs(q);
		for (int& q : qs) {
			cin >> q;
		}

		vector<int> ans;
		while (true) {
			auto limits = minmax_element(cur.begin(), cur.end());
			ans.push_back(*limits.second - *limits.first);
			if (*limits.second == 0) {
				break;
			}
			cur = transform(cur);
		}

		for (int i = 0; i < q; ++i) {
			cout << ' ';
			int q = qs[i];
   
      if (q < ans.size()) cout << ans[q]; 
      else cout << 0;
      cout << endl;
		}
	}
}
