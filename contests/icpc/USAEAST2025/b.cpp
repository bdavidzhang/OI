#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int D, n, v[100009], dep[100009], sz[29], tot, tl[100009], tr[100009]; 
int f[100009];
char t ;
char inv(char t) {
  if(t == 'A') return 'O';
  else return 'A';
}
int main () {
  cin >> D >> t; 
  sz[1] = 1; tot = 1; 
  vector<int> nums;
  for(int i=1;i<= D;++i) {
    for(int j=1;j<=sz[i]; ++j) {
      string s; cin>>s;
      if(s[0] == 'T' || s[0] == 'F') {
        v[++n] = s[0] == 'T';
      } else {
        int now = (s.size() == 1?s[0] - '0': 10);
        sz[i + 1] += now;
        tl[++n] = tot + 1, tr[n] = tot + now;
        tot += now; 
      }
      dep[n] = i;
    }
  }
  for(int i = n; i; --i) if (tl[i]){
    char op = t;
    if(dep[i] % 2 == 0) {
      op = inv(op);
    }
    if(op == 'A') {
      v[i] = 1;
    }
    for(int j=tl[i] ; j<=tr[i]; ++j) {
      if(op == 'A') v[i] &= v[j];
      else v[i] |= v[j];
    }
    if(op =='A') {
      if(v[i] ==true) {
        f[i] = 1e8;
        for(int j=tl[i]; j<=tr[i] ; ++j)
          f[i] = min(f[i], f[j]);
      } else {
        for(int j=tl[i]; j<= tr[i]; ++j) 
          if(v[j] == false) f[i] += f[j];
      }
    } else {
      if(v[i] == false) {
        f[i] = 1e8;
        for(int j=tl[i]; j<=tr[i] ; ++j)
          f[i] = min(f[i], f[j]);
      } else {
        for(int j=tl[i]; j<= tr[i]; ++j) 
          if(v[j] == true) f[i] += f[j];
      }
    }
  } else {
    f[i] = 1;
  }
  cout << f[1] << endl; 
  return 0; 
}