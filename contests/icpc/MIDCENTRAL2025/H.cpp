#include<vector>
#include<iostream>
using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin>> n >> k;
  vector<int> v(25);
  for(int i = 0; i < n; ++i){
    int a,b;
    cin >> a >> b;
    for (int j = a; j < b; ++j){
      v[j] += 1;
    }
  }

  int cnt = 0;
  for(int h = 0; h <= 24; ++h){
    if(v[h] >= k)  cnt++;
  }

  cout << cnt << '\n';

  return 0;
}
