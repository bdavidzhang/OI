#include <iostream>
#include <vector>

// Function to compute (base^exp) % mod efficiently
long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1000000007;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Base case for n=1
    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    // For n >= 2, the number of such permutations is n * 2^(n-2)
    long long mod = 1000000007;

    // Calculate 2^(n-2) using modular exponentiation
    long long power_of_2 = power(2, n - 2);

    // Calculate the final answer: (n * 2^(n-2)) % mod
    long long ans = (n * power_of_2) % mod;

    std::cout << ans << std::endl;

    return 0;
}