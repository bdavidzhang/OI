#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m, x[19], y[19];
int st[19][19], tmp[19][19]; 
struct dat{char type; int a,b,c,d;};
vector<dat> ans; 
char type[19];
string loc[19];
int kx[8] = {1,0,-1,0,1, -1, 1, -1};
int ky[8] = {0,1,0,-1,1,1,-1,-1};

int hx[8] = {2,2,-2,-2, 1,-1,1,-1};
int hy[8] = {1,-1,1,-1, 2,2,-2,-2};

int sgn(int x) {
  if(x == 0) return 0; 
  return x > 0?1:-1;
}

bool check1(int x,int y, int nx ,int ny) {
  if(abs(x - nx) != abs(y - ny)) return 0; 
  int dir1 = x > nx?-1:1, dir2 = y > ny ? -1 : 1;
  for(int k = 1; k < abs(x - nx); ++k)
    if(st[x + k * dir1][y + k * dir2]) return 0;
  return 1; 
}

bool check2(int x,int y,int nx, int ny) {
  if(abs(x - nx) > 0 && abs (y - ny) > 0) return 0;
  int dir1 = sgn(nx - x), dir2 = sgn(ny - y);
  for(int k = 1; k < max(abs(nx - x), abs(ny - y)); ++k)
    if(st[x + k * dir1][y + k * dir2]) return 0;
  return 1; 
}

bool check(int x,int y ,int nx ,int ny) {
  char tp = type[st[x][y]];
  if(tp == 'K') {
    for(int k = 0;k < 8; ++k) 
      if(x + kx[k] == nx && y + ky[k] == ny) return 1;
    return 0; 
  } else if(tp == 'N'){
    for(int k = 0; k < 8; ++k)
      if(x + hx[k] == nx && y + hy[k] == ny) return 1; 
      return 0;
  } else if(tp == 'B') return check1(x,y,nx,ny);
  else if(tp == 'R') return check2(x,y,nx,ny);
  else return check1(x,y,nx,ny) | check2(x,y,nx,ny);
}
bool dfs(int k) {
  if(k == 1) return 1; 
  vector<pair<int,int>> pos;
  for(int i=1;i<=n;++i) 
    for(int j=1;j<=n;++j){
      if(st[i][j] > 0) pos.emplace_back(i,j); 
    }
  
  for(auto p : pos) {
    int x = p.first, y = p.second;
    for(auto q : pos) if(q != p ){
      int nx = q.first, ny = q.second;
      if(check(x,y,nx,ny)) {
        int t1 = st[nx][ny];
        st[nx][ny] = st[x][y]; st[x][y] = 0; 
        if(dfs(k - 1)) {
          ans.push_back((dat){type[st[nx][ny]], x,y,nx,ny}); 
          st[x][y] = st[nx][ny]; st[nx][ny] = t1;
          return 1; 
        }
        st[x][y] = st[nx][ny]; st[nx][ny] = t1;
      }
    }
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n>> m;
  for(int i=1;i<=m;++i) {
    string cur;
    cin>>cur >> loc[i];
    type[i] = cur[0]; 
    x[i] = loc[i][0] -'A' + 1;
    y[i] = loc[i][1] - '1' + 1;
    st[x[i]][y[i]] = i;
  }

  if(dfs(m)) {
    reverse(ans.begin(), ans.end());
    for(auto x : ans) {
      cout << x.type << ": " << (char) (x.a +'A' - 1) << (char)(x.b + '0') << " -> " << (char) (x.c + 'A' - 1) << (char) (x.d + '0') << endl; 
    }
  } else {
    cout << "No solution" ; 
  }
  return 0;
}