#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

const int INF = 1e9;

double slope(double x1, double y1, double x2, double y2){
    if(x1 == x2){
        return INF;
    }
    return (double(y1)-y2)/(double(x1)-x2);
}

double b(double x1, double y1, double k){
    if(k == INF) return x1;
    return y1 - k*x1;
}

void solve(){
   int n;
   cin >> n;
   cout << "INTERSECTING LINES OUTPUT" << endl;
   for(double i = 0 ;i < n;++i){
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >>y2 >> x3 >> y3>> x4 >> y4;
        double k1 = slope(x1,y1,x2,y2);
        double b1 = b(x1,y1,k1);
        double k2 = slope(x3,y3,x4,y4);
        double b2 = b(x3,y3,k2);
        if(k1 == k2){
            if(b1 == b2) cout << "LINE" << endl;
            else cout << "NONE" << endl;
        }else if(k1 == INF){
            cout << fixed << setprecision(2)<< "POINT "<< b1 << " " << b1*k2+b2 << endl;
        }else if(k2 == INF){
            cout << fixed << setprecision(2)<< "POINT "<< b2 << " " << b2*k1+b1 << endl;
        }
        else{
            double x = (b2-b1)/(k1-k2);
            double y = k2*x+b2;
            cout << "POINT ";
            cout << fixed << setprecision(2) << x << " " << y << endl;
        }
   }
   cout << "END OF OUTPUT" << endl;
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

