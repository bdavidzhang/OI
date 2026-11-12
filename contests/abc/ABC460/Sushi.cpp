#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first 
#define se second
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;


void solve(){
  int n,m;
  cin >> n >> m;
  vll A(n), B(m);
  for(int i = 0; i < n; ++i) cin >> A[i];
  for(int i = 0; i < m; ++i) cin >> B[i];
  sort(all(A)); sort(all(B));

  // for(int i = 0; i < n; ++i) cout << A[i] << " ";
  // cout << endl;
  // for(int i = 0; i < m; ++i) cout << B[i] << " ";
  // cout << endl;

  int i = 0, j = 0;
  while(i < n && j < m){
    if(B[j] <= 2 * A[i]){
      // cout << A[i] << " " << B[j]<< endl;
      i++;
      j++;
    }else{
      i++;
    }
  }
  cout << j << '\n';

}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}