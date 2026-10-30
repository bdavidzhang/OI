#include<cstdio>
#include<vector>
#include<iostream>

void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    std::vector<int> r(n), c(m); //rows and columns
    for (int i = 0; i< n; ++i){
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j){
            r[i] += s[j] - '0';
            c[j] += s[j] - '0';
        }
    }
    for (int i = 0; i< n; ++i){
        std::string s; 
        std::cin >> s;
        for (int j = 0; j < m; ++j){
            r[i] -= s[j] - '0';
            c[j] -= s[j] - '0';
        }
    }

    bool flag = true;

    for (int i = 0; i< n; ++i){
        if (r[i] % 3 != 0) flag = false;
    }
    for (int j = 0; j < m; ++j){
        if (c[j] % 3 != 0) flag = false;
    }
    if(flag){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}



int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        solve();
    }



    return 0;
}
