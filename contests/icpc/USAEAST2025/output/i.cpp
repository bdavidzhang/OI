#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  vector<vector<bool>> vis(n,vector<bool>(n,false));
  for(int i = 0;i < n; ++i){
    for(int j = 0; j < i+1; ++j){
      int x;
      cin >> x;
      v[i].push_back(x);
      if(x == 100) vis[i][j] = true; 
    }
  }
  bool no_sol = false, amb = false, ok = true;
  int k = 0;
  while(k < 200 && ok){
    k++;
    for(int i = 0;i < n - 1; ++i){
      for(int j = 0; j < i+1; ++j){
        int cnt = 0;
        bool isx, isy, isz;
        int x = v[i][j];
        int y = v[i+1][j];
        int z = v[i+1][j+1];
        if(x == 100){
          cnt++;
          isx = true;
        }
        if(y == 100){
          cnt++;
          isy = true;
        }
        if(z == 100){
          cnt++;
          isz = true; 
        }
        if(cnt >= 2) continue;
        else if(cnt == 1){
          if(isx){
            x = y + z; 
            if(abs(x) >= 100 && vis[i][j] == false){
              cout << x << " " << k << endl;
              no_sol = true;
              ok = false;
            }else{
              v[i][j] = x;
              vis[i][j] = true;
            }
          }else if(isy){
            y = x - z; 
            if(abs(y) >= 100 && vis[i+1][j] == false){
              cout << y << " " << k << endl;
              no_sol = true;
              ok = false; 
            }else{
              v[i+1][j] = y;
              vis[i+1][j] = true;
            }
          }else{
            z = x - y; 
            if(abs(z) >= 100 && vis[i+1][j+1] == false){
              cout << z << " " << k << endl;
              ok = false;
              no_sol = true;
            }else{
              v[i+1][j+1] = z;
              vis[i+1][j+1] = true;
            }
          }
        }else{
          if(x != y+z || abs(x) >= 100 || abs(y) >= 100 || abs(z) >= 100){
            cout << x << " " << y << " " << z  << " " << k << endl;
            no_sol = true;
            ok = false;
          }
        }
      }
    }
  }//while loop ends
  for(int i = 0;i < n; ++i){
    for(int j = 0; j < i+1; ++j){
      cout << v[i][j] << " "; 
    }
    cout << endl;
  }

  if(no_sol){
      cout << "no solution" << endl;
    }else{
      for(int i = 0;i < n; ++i){
        for(int j = 0; j < i+1; ++j){
          if(v[i][j] == 100) amb = true; 
        }
      }
      if(amb){ 
        cout << "ambiguous" << endl;
      }else{
        cout << "solvable" << endl;
      }
    }
}
