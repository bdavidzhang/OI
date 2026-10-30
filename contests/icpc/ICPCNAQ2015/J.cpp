#include<bits/stdc++.h>
using namespace std;


void DFS(vector<string> &path, map<string, list<string>> &grid, string cur, map<string, bool> &visited){
    if(visited[cur]) return;
    visited[cur] = true;
     

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    cin.ignore();

    map<string, list<string>> grid;
    int sz;
    string start;
   
    for(int i = 0; i <n; ++i)
        string s;
        getline(cin,s); 
        vector<string> strs;
        string cur = "";

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                strs.push_back(cur); 
                cur = "";
            }else{
                cur+=s[i]; 
            }
        }
        if(i == 0) start = strs[0];


        for(int i = 1; i < strs.size(); ++i){
            grid[strs[0]].push(strs[i]); 
        }
    }
    //IO

    sz = grid.size(); 
    map<string, bool> visited(n,false);
 
    vector<string> path; 
    path.push_back(start);

    return 0;
}
