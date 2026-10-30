#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))


void solve(){

    int n;
    cin >> n;
    int s1,s2;
    cin >> s1;
    queue<int> q1, q2;
    for(int i = 0; i < s1; ++i){
        int x;
        cin >> x;
        q1.push(x);
    }

    cin>> s2;
    for(int i = 0 ; i < s2; ++i){
        int x;
        cin >> x;
        q2.push(x);
    }

    long long cnt = 0;
    while(!q2.empty() && !q1.empty() && cnt < 1e7){
        cnt++;
        int c1 = q1.front();
        int c2 = q2.front();

        q1.pop();
        q2.pop();
        if(c1 > c2){
            q1.push(c2);
            q1.push(c1);
        }else{
            q2.push(c1);
            q2.push(c2);
        }
    }

    if(q1.empty()){
        cout << cnt << " " << 2 << endl;
    }
    else if(q2.empty()){
        cout << cnt << " " << 1 << endl;
    }else if (cnt == 1e7){
        cout << -1 << endl;
    }
 
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
