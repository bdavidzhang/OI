#include <iostream>
#include <vector>
#include <algorithm>

// Using a struct can make the code more readable than a pair
struct Element {
    int value;
    int original_index;
};

// A comparison function is needed to sort the vector of structs
bool compareElements(const Element& a, const Element& b) {
    return a.value < b.value;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<Element> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].value;
        a[i].original_index = i;
    }

    // 1. Sort the elements by value
    std::sort(a.begin(), a.end(), compareElements);

    // 2. Calculate prefix sums on the sorted values
    std::vector<long long> pre(n);
    pre[0] = a[0].value;
    for (int i = 1; i < n; ++i) {
        pre[i] = a[i].value + pre[i - 1];
    }

    // 3. Find winners and assign answers
    std::vector<int> result(n);
    // The largest element is always a "winner" in its group.
    // The number of additional items it can collect is n-1.
    result[a[n - 1].original_index] = n - 1;

    // Iterate from the second-to-last element backwards
    for (int i = n - 2; i >= 0; --i) {
        // If this element's group can't "bridge the gap" to the next element...
        if (pre[i] < a[i + 1].value) {
            // ...then its answer is just the number of elements up to itself (i.e., i additional items).
            result[a[i].original_index] = i;
        } else {
            // ...otherwise, it joins the "winning group" of the element to its right,
            // so it gets the same answer.
            result[a[i].original_index] = result[a[i + 1].original_index];
        }
    }

    // 4. Print the results in the original order
    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    // Faster I/O is good practice in competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}