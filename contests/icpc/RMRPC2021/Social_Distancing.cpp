#include<bits/stdc++.h>
using namespace std;

int main(){
    int S, N;
    cin >> S >> N;
    vector<int> seats;

    for(int i = 0;i < N; ++i){
        int x;
        cin >> x;
        seats.push_back(x);
    }
    int cnt = 0;
    for(int i = 0; i < N-1; ++i){
        int dist = abs(seats[i+1] - seats[i]);
        dist--;
        // cout << dist << endl;
        cnt += (dist-1)/2;
    }
    int dist = seats[0] + S - seats[N-1];
    dist--;
    // cout << dist << endl;
    cnt += (dist-1)/2;

    cout << cnt << endl;
    return 0;
}