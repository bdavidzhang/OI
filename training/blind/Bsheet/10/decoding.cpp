#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


void solve(){
    int n; 
    cin >> n;
    string s;
    cin >> s;
    vector<char> ans(n);
    int cnt;
    if(n == 1 || n == 2){
        cout << s << endl;
        return;
    }
    else if(n == 3){
        cout << s[1] << s[0] << s[2] << endl;
        return; 
    }
    if(n % 2 == 0){
        int mid = n/2-1;
        int d = (n-1)/2;
        ans[mid] = s[0];
        cnt = 1;
        for(int i =1; i <= d; ++i){
            ans[mid+i] = s[cnt++];
            ans[mid-i] = s[cnt++];
        }
        ans[n-1] = s[n-1];
    }else{
        int mid = n/2;
        int d = (n-1)/2;
        ans[mid] = s[0];
        cnt = 1;
        for(int i = 1;i <= d; ++i){
            ans[mid-i] = s[cnt++];
            ans[mid+i] = s[cnt++];
        }
    }
    for(int i = 0;i < n; ++i){
        cout << ans[i];
    }
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
