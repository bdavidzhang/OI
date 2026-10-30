#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,s,p,q;
    cin >> n >> m >> s >> p >> q;
    set<int> neg, pos, inter;
    for(int i = 0; i < p; ++i){
        int x;
        cin >> x;
        neg.insert(x);
    }
    for(int i = 0; i < q; ++i){
        int x;
        cin >> x;
        pos.insert(x);
    }
    set_insertion(all(neg),all(pos),inserter(inter,inter.begin()));
    
    return 0;
}