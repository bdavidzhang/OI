#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

bool topoutil(int i, vii &g, stack<int> &s, vb &vs, vb &recstack){
    vs[i] = true;
    recstack[i] = true;

    for(int x : g[i]){
        if(!vs[x] && topoutil(x,g,s,vs,recstack)) return true;
        else if (recstack[x]) return true;
    }
    s.push(i);
    recstack[i] = false;
    return false;

}

bool topo(vii &g, stack<int> &s){
   vb vs(3);
   vb recstack(3);
   bool res = false;
   for(int i = 0; i< 3; ++i){
       if(!vs[i])
       res = res || topoutil(i,g,s,vs,recstack); 
   }
   return res;
}




int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, int> mp;
    for(int i = 0; i< 3;++i){
        mp.insert({char(int('A')+i),i});
    }
    map<int, char> rev;
    for(int i = 0; i< 3;++i){
        rev.insert({i,char(int('A')+i)});
    }

    vii g(3);
    for(int i = 0; i <3;++i){

        string s;
        cin >> s;
        if(s[1] == '>')g[mp[s[2]]].push_back(mp[s[0]]);
        else g[mp[s[0]]].push_back(mp[s[2]]);
    }

    stack<int> s;
    bool res = topo(g,s);

    if(res){
        cout << "Impossible";
    }else{
        while(!s.empty()){
            cout << rev[s.top()];
            s.pop();
        }
    }
    cout << endl;

    return 0;
}
