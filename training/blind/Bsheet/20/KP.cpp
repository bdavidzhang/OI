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
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    set<pair<int,int>> pts;

    for(int i = 0 ;i < n; ++i){
        int r,a,b;
        cin >> r >> a >> b;
        for(int j = a; j <= b; ++j){
            pts.insert({r,j});
        }
    }
   
    map<pair<int,int>,int> len;
    pair<int,int> cur = {x1,y1};
    int dx[] = {1,0,-1,0,1,1,-1,-1};
    int dy[] = {0,1,0,-1,1,-1,1,-1};
    queue<pair<int,int>> q;

    q.push(cur);
    len[cur] = 0;
    int dep = 0;
    int sz = 1;
    for(; !q.empty(); sz = q.size(), dep++){
        while(sz--){
            cur = q.front();
            q.pop();

            for(int d = 0; d < 8; ++d){
                int nx = cur.first + dx[d];
                int ny = cur.second + dy[d];

                pair<int,int> newp = {nx,ny};

                if(pts.count(newp) == 0 || len.count(newp) != 0){
                    continue;
                }
                
                q.push(newp),len[newp] = dep+1;
                if(nx == x2 && ny == y2){

                    cout << dep+1 << endl;
                    return;
                }
            }
        }
    }

    cout << -1 << endl;
    return ;
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
