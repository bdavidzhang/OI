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

    int a,b;
    cin >> a >> b;

    int x;
    if ( a== b) x = 1;
    else{
        x = floor(log(double(b)/a)/log(double(3)/2))+1;
    }
    cout << x << endl;


    return 0;
}
