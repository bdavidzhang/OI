#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

int mp(int n, int p){
    int s = 0;
    for(int i = 1; i <= 3; ++i){
        s += n/(pow(p,i));
    }
    return s;
}

void solve(){
   int n;
   cin >> n;
   map<int,int> pc;
   pc[2] = 0;
   pc[3] = 0;
   pc[5] = 0;
   pc[7] = 0;
    string s;
    cin >> s;
   for(int i = 0; i < n; ++i){
        int x = int(s[i] - '0');
        pc[2] += mp(x,2);
        pc[3] += mp(x,3);
        pc[5] += mp(x,5);
        pc[7] += mp(x,7);
   }
   int a,b,c,d;
    d = pc[7];
    pc[7] -= d;
    pc[5] -= d;
    pc[3] -= 2*d;
    pc[2] -= 4*d;
    c = pc[5];
    pc[5] -= c;
    pc[3] -= c;
    pc[2] -= 3*c;
    b = pc[3];
    pc[3] -= b;
    pc[2] -= b;
    a = pc[2];
    pc[2] -= a;
    for(int i = 0; i < d; ++i)cout << 7;
    for(int i = 0; i < c; ++i)cout << 5;
    for(int i = 0; i < b; ++i)cout << 3;
    for(int i = 0; i < a; ++i)cout << 2;

    cout << endl;

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1e9+7; 
    //cin >> t;
    for(int i = 0; i < t; ++i){
        if(t == 1e9+7){
            solve();
            break;
        }
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
