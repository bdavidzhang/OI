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

    vii g(5,vi(5));
    int x,y;
    for(int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; j++) {
           cin >> g[i][j];
           if(g[i][j] == 1){
                x = i;
                y = j;
           }
        }
    }

    cout << abs(x-2) + abs(y-2) << endl;

   

    return 0;
}
