#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("brute_out.txt", "w", stdout);  // change to "brute_out.txt" for brute.cpp
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Example computation: sum of array
    cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
}
