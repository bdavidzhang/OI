//Sun and moon
#include<bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int curs, sun;
    int curm, moon;

    cin >> curs >> sun;
    cin >> curm >> moon;

    // sun and moon need to be aligned, we can just simulate 

    long long ans = 0;
    for(int i = 1; i < 5005; ++i){
        curs++;
        curs %= sun;
        curm++;
        curm %= moon;
        if(curs == curm){
            ans = i;
            break;
        }
    }

    cout << ans << endl;


 }