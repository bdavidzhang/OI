#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    set<int> blocks;

    while(q--){
        char t;
        cin >> t;
        // for(auto &x : blocks) cout << x << " ";
        // cout << endl;
        if(t == '+'){
            int x;
            cin >> x;
            blocks.erase(x);
        }else if(t == '-'){
            int x;
            cin >> x;
            blocks.insert(x);
        }else if(t == '?'){
            int a,b;
            cin >> a >>b;
            if(blocks.empty()){
                cout << "possible" << endl;
                continue;
            }

            if(a > b) swap(a,b);

            bool bin = false;
            auto it = blocks.lower_bound(a);
            if(*it == a){
                cout << "impossible" << endl;
                continue;
            }
            if (it!=blocks.end() && *it < b) bin = true; 

            bool bout = false;
            it = blocks.lower_bound(b);
            if(*it == b){
                cout << "impossible" << endl;
                continue;
            } 
            if (it!=blocks.end()) bout = true;  
            else{
                it = blocks.lower_bound(0);
                if (it!=blocks.end() && *it < a) bout = true;  
            }

            if(bin && bout) cout << "impossible" << endl;
            else cout << "possible" << endl;
        }
        
    }


    return 0;
}