#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int cnts = 0, cntm = 0, cntl = 0;
  for(int i = 0; i < n; ++i){
    char c;
    int x;
    cin >> c >> x;
    if(c == 'S') cnts += x;
    else if(c == 'M') cntm += x;
    else if(c == 'L') cntl += x;
  }

  cout << (cnts + 5) / 6 + (cntm + 7) / 8 + (cntl + 11) / 12 << endl;
}