#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int p,q; cin >> p >> q;
  bool flag = 0;
  for(int r=1; r<= 1000000; ++r) {
    long long k = (long long)(p + 2 * q * r ) * (p + 2 * q * r) - (long long) 8 *p * q * r * r;
    long long kk = sqrt(k);
    if(kk * kk == k) {
      long long now = p + 2 * q * r + kk ;
      if(now %(2 * p) == 0) {
        long long s = now / (2 * p); 
        cout << r << " " << s - r << endl; 
        flag = 1;
        break;
      }
    }
  }

  if(!flag)cout << "impossible" << endl; 
  return 0;
}