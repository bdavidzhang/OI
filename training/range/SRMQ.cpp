#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;  // limit for array size
int n;  // array size
int q;
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1],t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p],t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 1e9;
  if(l == r) res = t[l+n];
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res,t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
}


void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}

int main() {
  cin >> n >>  q;
  for (int i = 0; i < n; ++i) cin >> t[n+i];
  build();
  for (int i = 0; i < q; i++) {
      int a,b;
      cin >> a >> b;
      cout << query(a-1,b-1) << endl;
  } 

  return 0;
}
