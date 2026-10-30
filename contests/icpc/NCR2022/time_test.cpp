#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100000; // 1e5 lines

    // // --- Method 1: print line by line ---
    // auto start1 = high_resolution_clock::now();
    // for (int i = 0; i < N; i++) {
    //     cout << i << '\n';
    // }
    // auto end1 = high_resolution_clock::now();
    // cerr << "Line-by-line time: "
    //      << duration_cast<milliseconds>(end1 - start1).count()
    //      << " ms\n";

    // // --- Reset output buffer ---
    // cout.flush();

    // // --- Method 2: build string and print once ---
    // string big;
    // big.reserve(N * 8); // pre-allocate memory
    // auto start2 = high_resolution_clock::now();
    // for (int i = 0; i < N; i++) {
    //     big.append(to_string(i));
    //     big.push_back('\n');
    // }
    // cout << big;
    // auto end2 = high_resolution_clock::now();
    // cerr << "Buffered time: "
    //      << duration_cast<milliseconds>(end2 - start2).count()
    //      << " ms\n";

    return 0;
}
