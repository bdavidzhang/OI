#include <bits/stdc++.h>
using namespace std;

const int STATE_COUNT = 8;
const int NEGATIVE_INFINITY = -1000000000;
const int masks[STATE_COUNT] = {0, 3, 5, 6, 9, 10, 12, 15};

struct Matrix {
	int best[STATE_COUNT][STATE_COUNT];

	Matrix(int initial_value = NEGATIVE_INFINITY) {
		for (auto& row : best) {
			fill(row, row + STATE_COUNT, initial_value);
		}
	}
};

Matrix combine(const Matrix& left, const Matrix& right) {
	Matrix result;
	for (int incoming = 0; incoming < STATE_COUNT; ++incoming) {
		for (int middle = 0; middle < STATE_COUNT; ++middle) {
			if (left.best[incoming][middle] == NEGATIVE_INFINITY) {
				continue;
			}
			for (int outgoing = 0; outgoing < STATE_COUNT; ++outgoing) {
				result.best[incoming][outgoing] = max(
					result.best[incoming][outgoing],
					left.best[incoming][middle] + right.best[middle][outgoing]
				);
			}
		}
	}
	return result;
}

Matrix make_leaf(int value) {
	Matrix result;
	for (int incoming = 0; incoming < STATE_COUNT; ++incoming) {
		for (int outgoing = 0; outgoing < STATE_COUNT; ++outgoing) {
			int final_value = value ^ masks[incoming] ^ masks[outgoing];
			result.best[incoming][outgoing] = (final_value % 3 == 0);
		}
	}
	return result;
}

Matrix make_identity() {
	Matrix result;
	for (int state = 0; state < STATE_COUNT; ++state) {
		result.best[state][state] = 0;
	}
	return result;
}

struct SegmentTree {
	int size;
	vector<Matrix> tree;

	SegmentTree(const vector<int>& values) {
		size = 1;
		while (size < static_cast<int>(values.size())) {
			size *= 2;
		}
		tree.assign(2 * size, make_identity());
		for (int index = 0; index < static_cast<int>(values.size()); ++index) {
			tree[size + index] = make_leaf(values[index]);
		}
		for (int index = size - 1; index > 0; --index) {
			tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
		}
	}

	void update(int index, int value) {
		index += size;
		tree[index] = make_leaf(value);
		for (index /= 2; index > 0; index /= 2) {
			tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
		}
	}

	int answer() const {
		return tree[1].best[0][0];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, q;
		cin >> n >> q;
		vector<int> vals(n);
		for (int& val : vals) {
			cin >> val;
		}

		SegmentTree tree(vals);
		cout << tree.answer();
		while (q--) {
			int pos, val;
			cin >> pos >> val;
			tree.update(pos - 1, val);
			cout << ' ' << tree.answer();
		}
		cout << '\n';
	}
}
