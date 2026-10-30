#include<bits/stdc++.h>
using namespace std;

void solve(int ta, int tb){
    long long sa = 0;
    for (int i = 0; i < ta; ++i){
        int t;
        cin >> t;
        sa += t; 
    }
    long long sb = 0;
    for (int i = 0; i < tb; ++i){
        int t;
        cin >> t;
        sb += t; 
    }
    cout << -sb+sa << endl;
    
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ta, tb;
    while(cin >> ta){
        cin >> tb;
        solve(ta,tb);

    }



    return 0;
}
//then you will find joy in the LORD
//I will cause you to ride in triumph on
//the heights of the land
//and to feast on the inheritance of your father Jacob
