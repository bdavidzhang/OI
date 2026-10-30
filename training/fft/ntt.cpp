#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}


int main() {
    // A(x) = x + 2  --> {2, 1}
    // B(x) = 3x + 4 --> {4, 3}
    vector<int> A = {2, 1};
    vector<int> B = {4, 3};

    // 1. Determine size
    int n = 1;
    while (n < A.size() + B.size()) n <<= 1; // n will become 4

    // 2. Pad with zeros
    A.resize(n); // A is now {2, 1, 0, 0}
    B.resize(n); // B is now {4, 3, 0, 0}

    // 3. Forward NTT
    fft(A, false);
    fft(B, false);

    // 4. Pointwise Product
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        C[i] = (int)(1LL * A[i] * B[i] % mod);
    }

    // 5. Inverse NTT
    fft(C, true);

    // Result C should be {8, 10, 3, 0}
    // which corresponds to 3x^2 + 10x + 8
    cout << "Resulting coefficients: ";
    for (int i = 0; i < A.size() + B.size() - 1; ++i) {
        cout << C[i] << " ";
    }
    cout << endl; // Output: Resulting coefficients: 8 10 3 

    return 0;
}