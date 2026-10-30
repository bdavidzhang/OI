#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;
  vector<long long> v(n);
  long long tot = 0;
  for(int i = 0; i < n; ++i){
    cin>>v[i];
    tot += v[i];
  }
  long long goal = 0;
  if(tot % 2 ==0){
    goal = tot / 2 + 1;
  }else{
    goal = (tot+1) /2;
  }
  sort(v.begin(),v.end());
  if(tot - v[n-1] < goal){
    cout << "IMPOSSIBLE TO WIN" << endl;
    return 0;
  }

  long long cnt = 0;
  long long cur = v[n-2]; 
  for(int i = 0; i < n-2; ++i){
    cur += v[i]; a
    cnt++;
    if(cur >= goal){
      cout << cnt << endl; 
      return 0;
    }
  }

  return 0;

}