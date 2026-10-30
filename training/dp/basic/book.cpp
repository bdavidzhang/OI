#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,x;
    cin >> n>>x;
    vector<int> h(n);
    vector<int> s(n);

    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }

    vector<pair<int,int>> hs(n);
    for(int i = 0;i < n; ++i){
        hs[i] = {h[i], s[i]};
    }

    sort(hs.begin(),hs.end());

    vector<int> pages(x+1);
    
    pages[hs[0].first] = hs[0].second;
    for(int i = hs[0].first + 1; i <= x; ++i){
        pages[i] =     }


    return 0;

}


