#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
long long a[N];     // input array
long long b[N];     // merged results (like queue)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);  // O(n log n)

    int i = 0, j = 0, k = 0;  // i->a, j->b, k->b (merged)
    long long ans = 0;

    while (i + j < n - 1) {  // need n-1 merges
        long long x = LLONG_MAX, y = LLONG_MAX;

        // get smallest 2 among a[i], b[j]
        if (i < n && (j >= k || a[i] < b[j])) x = a[i++];
        else x = b[j++];

        if (i < n && (j >= k || a[i] < b[j])) y = a[i++];
        else y = b[j++];

        long long s = x + y;
        ans += s;
        b[k++] = s;
    }

    cout << ans << '\n';
    return 0;
}
