// D - Concentric Circles
// https://atcoder.jp/contests/abc467/tasks/abc467_d  (2000 ms, 1024 MB)
#include <bits/stdc++.h>
using namespace std;
using db = double;
const db eps = 1e-9, PI = acos(-1.0);
int sgn(db x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }
struct Pt {
    db x, y;
    Pt(db x = 0, db y = 0) : x(x), y(y) {}
    Pt operator+(Pt b) const { return Pt(x + b.x, y + b.y); }
    Pt operator-(Pt b) const { return Pt(x - b.x, y - b.y); }

};

istream& operator>>(istream& in, Pt& p) { return in >> p.x >> p.y; }
db dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }


const double EPS = 1e-9;

// Gauss elimination function
// A is the augmented matrix of size n x (m + 1), where m is number of variables
// Returns: 0 = no solution, 1 = unique solution, 2 = infinite solutions
int gauss(vector<vector<double>> a, int n, int m, vector<double> &ans) {
    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i) {
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        }
        ++row;
    }

    ans.assign(m, 0);
    for (int i = 0; i < m; ++i) {
        if (where[i] != -1) {
            ans[i] = a[where[i]][m] / a[where[i]][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0; // No solution
    }

    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return 2; // Infinite solutions

    return 1; // Unique solution
}

void solve(){
  Pt P,Q,R,S;
  cin >> P >> Q >> R >> S;
  vector<vector<db>> inp = {{2*(-P.x+Q.x),2*(-P.y+Q.y),(P.x+Q.x)*(-P.x+Q.x)+(P.y+Q.y)*(-P.y+Q.y)},
    {2*(-R.x+S.x),2*(-R.y+S.y),(R.x+S.x)*(-R.x+S.x)+(R.y+S.y)*(-R.y+S.y)}};

  vector<db> ans;
  int res = gauss(inp,2,2,ans);
  if(res == 0) cout << "No" << endl;
  else{
    Pt O = {ans[0],ans[1]};
    bool ok1 = (dot(O-P,O-P) - dot(O-Q,O-Q) < eps), ok2 = (dot(O-R,O-R) - dot(O-S,O-S) < eps);
    if(ok1 && ok2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  for(auto x : ans) cout << x << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >>T ;
  while(T--) solve(); 
}
