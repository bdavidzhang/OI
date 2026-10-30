#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi c(n);
    for(int i= 0;i <n;++i){
        cin >> c[i];
    }

    sort(c.begin(),c.end());
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";  
    }
    cout << endl;

    return 0;
}
