#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first 
#define se second
using ll = long long;
using vi = vector<int>;


void solve(){
  ll X1,Y1,R1,X2,Y2,R2;
  cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
  ll d2 = (X1 - X2)*(X1 - X2) + (Y1-Y2) * (Y1 - Y2); 
  // cout << d2 << endl;
  ll Rsq1 = (R1+R2)*(R1+R2);
  ll Rsq2 = (R1-R2)*(R1-R2);
  // cout << Rsq1 << endl;
  if(d2 <= Rsq1 && d2 >= Rsq2) cout << "Yes" << '\n';
  else cout << "No" << '\n';


}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T--)solve();

  return 0;
}