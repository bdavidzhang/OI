#include<iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std; 


int n,m,st1, st2, st3, st4; 
int qr1, qr2, qr3, qr4;
int d[19][19][19][19][16];
struct dat {
    int r1,c1,r2,c2,st;
};
string a[19];
queue<dat> q; 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int  ck(char c){
    if(c>='A' && c<='D') return 1;
    if(c>='a' && c<='d') return 2;
    return 0;
}
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        a[i] = " " + a[i];
        for(int j=1;j<=m;++j) {
            if(a[i][j] == 'S') {
                if(st1 > 0) st3 = i, st4 = j;
                else st1 = i, st2 = j; 
            } else if (a[i][j] =='E') {
                if(qr1 > 0) qr3 = i, qr4 = j;
                else qr1 = i, qr2 = j;
            }
        }
    }
    memset( d , -1 ,sizeof d );
    d[st1][st2][st3][st4][0] = 0;
    q.push((dat){st1, st2,st3,st4, 0});
    while(q.size()) {
        dat now = q.front(); q.pop();
        int r1 = now.r1, c1 = now.c1, r2 = now.r2, c2 = now.c2,st = now.st;
        if(r1 == qr1 && c1 == qr2 && r2 == qr3 && c2 == qr4 || r1 == qr3 && c1 == qr4 && r2 == qr1 && c2 == qr2) {
            cout << d[r1][c1][r2][c2][st] << endl; 
            return 0;
        }
        for(int k = 0;k < 4; ++k) {
            int nr1 = r1 + dx[k], nc1= c1 + dy[k], nr2 = r2 + dx[k], nc2 = c2 + dy[k],nst = st;
            if (min(nr1, nr2) < 1 || max(nr1,nr2) > n || min(nc1 ,nc2) < 1 || max(nc1, nc2) > m)continue;
            if(a[nr1][nc1] == '*' || a[nr2][nc2]  =='*') continue;
            if(a[nr1][nc1] == '#')nr1 = r1, nc1 = c1; 
            if(a[nr2][nc2] == '#') nr2 = r2, nc2 = c2;
            if(ck(a[nr1][nc1])) {
                char s = ck(a[nr1][nc1]) ==1?'A':'a';
                int w = a[nr1][nc1] -s;
                if( ( ( ck(a[nr1][nc1]) - 1 ) ^ ( ( st >> w ) & 1 ) ) == 0) 
                    nr1 = r1, nc1 = c1; 
            } 
            if(ck(a[nr2][nc2])) {
                char s = ck(a[nr2][nc2]) ==1?'A':'a';
                int w = a[nr2][nc2] - s;
                if( ( (ck(a[nr2][nc2]) -1 ) ^ ( ( st >> w ) & 1 )) == 0) 
                    nr2 = r2, nc2 = c2;
            }
                
            if(nr1 == nr2 && nc1 == nc2) continue; 

            if( isdigit(a[nr1][nc1]) ) {
                int w = (a[nr1][nc1]  - '1');
                if( nr1 != r1 || nc1 != c1 ) {
                  nst ^= (1 << w);
                  if(ck(a[nr2][nc2]) ) {
                      char s = ck(a[nr1][nc1]) == 1 ?'A':'a';
                      int v = a[nr2][nc2] - s; 
                      if(w == v && ( ( ck(a[nr2][nc2] ) - 1 ) ^ ( ( st >> w ) & 1 ) ) ) { 
                          continue; 
                      }
                  }
                }
            }

            if( isdigit(a[nr2][nc2]) ) {
                int w = (a[nr2][nc2]  - '1');
                if( nr2 != r2 || nc2 != c2 ) {
                  nst ^= (1 << w);
                  if(ck(a[nr1][nc1]) ) {
                      char s = ck(a[nr2][nc2]) == 1 ?'A':'a';
                      int v = a[nr1][nc1] - s; 
                      if(w == v && ( ( ck(a[nr1][nc1] ) - 1 ) ^ ( ( st >> w ) & 1 ) ) ) { 
                          continue; 
                      }
                  }
                }
            }

            if(d[nr1][nc1][nr2][nc2][nst] == -1) {
                d[nr1][nc1][nr2][nc2][nst] = d[r1][c1][r2][c2][st] + 1;
                q.push((dat){nr1,nc1,nr2,nc2,nst});
            }
        }
    }
    
    return 0; 
}