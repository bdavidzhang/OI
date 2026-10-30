#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using ld = long double;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))
#define fi first
#define se second

void solve(){
   ld x1,y1,x2,y2,a;
   cin >> x1 >> y1 >> x2 >> y2 >> a;
   a /= 2;
   pair<ld,ld> mid = make_pair((x1+x2)/2,(y1+y2)/2);
   ld k = (y2-y1)/(x2-x1);
   x1 -= mid.fi;
   y1 -= mid.se;
   x2 -= mid.fi;
   y2 -= mid.se;
   ld c = sqrt(pow(x1,2)+pow(y1,2));
   ld b = sqrt(pow(a,2)-pow(c,2));
   ld tA = k;
   ld si = k*k/(1+k*k);
   ld co = 1/(1+k*k);
   ld xT = sqrt(a*a*co+b*b*si);
   ld yT = sqrt(a*a*si+b*b*co);
   ld xB = -xT;
   ld yB = -yT;
   cout << fixed << setprecision(7) << xB+mid.fi << " " << yB+mid.se << " " << xT+mid.fi << " " << yT+mid.se << endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1e9+7; 
    //cin >> t;
    for(int i = 0; i < t; ++i){
        if(t == 1e9+7){
            solve();
            break;
        }
    }
    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
