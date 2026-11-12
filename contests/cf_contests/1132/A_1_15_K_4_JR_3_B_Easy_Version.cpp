#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  int x = n / 2; 
  int y = n - x;
  cout << (long long) x * y << '\n';


}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >>T ;
  while(T--)solve();


  return 0;
}