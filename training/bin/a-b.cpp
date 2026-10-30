//A-B arrays - LUOGU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;

int findfirst(vi &v, int val){
    int lo = 0, hi = v.size()-1;
    int res = -1;
    while( lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid] == val){
            res = mid;
            hi = mid - 1;
        } else if(v[mid] < val){
            lo = mid+1;
        } else{
            hi = mid-1;
        }
    }
    return res;
}

int findlast(vi &v, int val){
    int lo = 0, hi = v.size()-1;
    int res = -1;
    while( lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid] == val){
            res = mid;
            lo = mid+1;
        } else if(v[mid] < val){
            lo = mid+1;
        } else{
            hi = mid-1;
        }
    }
    return res;
}


void solve(){
    int n,c;
    cin >> n >> c;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; 
    }
    sort(v.begin(), v.end());
    ll cnt = 0;        
    for (int i = 0; i < n; i++) {
        if(findfirst(v,c+v[i]) != -1)
        cnt += findlast(v,c+v[i]) - findfirst(v,c+v[i]) +1;
    }

    cout << cnt << endl; 

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
  

    return 0;
}

