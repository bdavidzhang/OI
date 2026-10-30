#include<bits/stdc++.h>
using namespace std;

int n;
string s; 
int stk[5009], top;
vector<int> to[5009]; 
int ans; 
bool match(char a, char b) {
    return a == '(' && b == ')' || a =='[' && b == ']' || a == '{' && b == '}';
}
void dfs(int u,int fa) {
    int tmp = 0;
    if(s[u] =='(' || s[u] == '{' || s[u] == '[') {
        stk[++top] = u; 
    }   else if(top > 0 && match(s[stk[top]], s[u])) {
        tmp = stk[top], --top;
    }else stk[++top] = u; 
    if(top  ==0) ++ans;
    for(auto v : to[u]) if (v != fa) { 
        dfs(v,u);
    }
    if(s[u] =='(' || s[u] == '{' || s[u] == '[') {
        --top;
    }   else if(tmp > 0) {
        stk[++top] = tmp;
    }else --top;
}
int main() {
    cin >> n;
    cin >> s; s = " " + s; 
    for(int i=1;i<n;++i) {
        int u,v; cin>>u>>v;
        to[u].push_back(v); to[v].push_back(u);
    }
    for(int i=1;i<=n;++i) {
        top = 0; dfs(i,0);

    }
    cout << ans << endl; 
    return 0; 
}