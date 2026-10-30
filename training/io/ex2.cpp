#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();
    cout << "test" << endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << duration.count() << endl;

    return 0;
}