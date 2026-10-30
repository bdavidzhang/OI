#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int l,w,n;
    cin >> l >> w >> n;
    if(l * w % n != 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int a,b;
    for(int i = 1; i <= l; ++i){
        for(int j = 1; j <= w; ++j){
            if(l % i == 0 && w % j == 0 && i*j*n == l*w){
                a = i;b=j;
                goto done;
            }
        }
    }
    done:;
    vector<vector<char>> ans(l,vector<char>(w));

    for(int i = 0; i < l; ++i){
        for(int j = 0; j < w; ++j){
            ans[i][j] = 'A' + (i/a)*(w/b) + (j/b);
            cout << ans[i][j];
        }
        cout << endl;
    }


    return 0;
}