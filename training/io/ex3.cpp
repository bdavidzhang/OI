#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();
    printf("test\n");
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    printf("%f",&duration);

    return 0;
}