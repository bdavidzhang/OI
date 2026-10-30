#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


bool prime(int n){
    for(int i = 2; i < sqrt(n)+1; ++i){
        if(n % i == 0) return false;
    }
    return true;
}





void solve(){
   int n;
   cin >> n;
   if(n % 2 == 0){
        cout << -1 << endl;
   }else{
            for(int i = 0; i < n; ++i){
                cout << i << " ";
            }
            cout << endl;
            for(int i = 0; i < n; ++i){
                cout << i << " ";
            }
            cout << endl;
            for(int i = 0; i < n; ++i){
                cout << (2*i)% n << " ";
            }
            cout << endl;
   }
   return;
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
