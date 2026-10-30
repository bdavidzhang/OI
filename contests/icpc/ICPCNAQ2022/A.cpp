#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ;
    cin >> n;

    vector<int> s(n);
    for(auto &x : s) cin >> x;
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    set<int> stb;
    stb.insert(s[0]);
    set<int> temp;
    long long sum = 0;
    long long sts = s[0];
    for(int i = 1; i< n; ++i){
        temp.insert(s[i]);
        sum += s[i];
        if(sum >= sts){
            sts += sum;
            sum = 0;
            for(int x : temp)
                stb.insert(x);
            temp.clear();
        }
    }

    cout << stb.size() << endl;


    return 0;
}
