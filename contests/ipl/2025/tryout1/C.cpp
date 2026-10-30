#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    unordered_map<char,int> freq;
    for(auto& c: s){
        freq[c]++;
    }
    vector<pair<char,int>> v(freq.begin(),freq.end());

    sort(v.begin(),v.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });

    int ans = 0;
    for(int i = 2; i < v.size(); ++i){
        ans += v[i].second;
    }

    cout << ans << endl;

    return 0;
}