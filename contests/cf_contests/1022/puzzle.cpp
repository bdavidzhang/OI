#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if (b == 0){
        return a;
    }
    if (a < b){
        swap(a,b);
    }
    return gcd(b,a%b);
}

int main(){
    int t;
    cin >> t;
    cout << t << endl;
    while(t--){
    int p, s;
    cin >> p >> s;
    int d = gcd(p,s);
    p %= d;
    s %= d;
    if(p % 2 != 0){
        p *= 2;
        s *= 2;
    }

    bool good = false;
    vector<pair<int,int>> out;
    for(int a = s; a < 50001; a += s){
        long long pp = a*p;
        long long hp = pp/2;
        long long w = hp/2;
        long long h = hp-w;
        if (a >= w+h-1 && a <= w*h){
            good = true;
            for(int i = 0; i < w; ++i){
                out.push_back({i,0});
                a-=1;
            }
            for (int i = 1; i < h; ++i){
                out.push_back({0,i}); 
                a-=1;
            }
            for (int i = 1; i < w; ++i){
                for (int j = 1; j < h; ++j){
                    if(a){
                        out.push_back({i,j});
                        a-=1;
                    }
                }
            }
            
        }
    }
    if(good){
        cout << out.size() << endl;
        for (auto &x : out){
            int c = x.first;
            int d = x.second;
            cout << c << " " << d << endl;
        }

    }else{
        cout << -1 << endl;
    }
}
}