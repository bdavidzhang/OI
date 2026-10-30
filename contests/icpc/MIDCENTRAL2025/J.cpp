#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;



const int mod = LLONG_MAX;

long long power(long long base, long long exp) {
	long long res = 1; base %= mod;
	while (exp > 0) {
		if (exp % 2 == 1) res = (res * base) % mod;
		base = (base * base) % mod;
		exp /= 2;
	}
	return res;
}

long long modInverse(long long n) {
	return power(n, mod - 2);
}

long long intDet(vector<vector<long long>>& a) {
	int n = sz(a); long long res = 1;
	rep(i,0,n) {
		int b = i;
		rep(j,i+1,n) if (abs(a[j][i]) > abs(a[b][i])) b = j;
		if (i != b) swap(a[i], a[b]), res = (mod - res) % mod;
		res = (res * a[i][i]) % mod;
		if (res == 0) return 0;
		long long inv = modInverse(a[i][i]);
		rep(j,i+1,n) {
			long long v = (a[j][i] * inv) % mod;
			if (v != 0) rep(k,i+1,n) {
				a[j][k] = (a[j][k] - v * a[i][k]) % mod;
				if (a[j][k] < 0) a[j][k] += mod;
			}
		}
	}
	return (res + mod) % mod;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin>> n;
  vector<vector<int>> A(n,vector<int>(n,0));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> A[i][j];
    }
  }

  for(int i = 0; i
  

  


  
  return 0;
}
