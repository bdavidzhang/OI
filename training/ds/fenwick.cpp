
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
vector<int> Tr(MAXN);
vector<int> v(MAXN);
int n;

void make(){

    for(int i = 1; i <= n; ++i){
        Tr[i] = v[i];
    }

    for(int i = 1; i <= n; ++i){
        int p = i + (i & -i);
        Tr[p] = Tr[p] + Tr[i];
    }
}

long long sum(int i){
    long long ans = 0;
    while(i > 0){
        ans += Tr[i];
        i -= i & -i;
    }
    return ans;
}

void add(int i, int val){
    while(i <= n){
        Tr[i] += val;
        i += i & -i;
    }
}

int main(){
    n = 8;
    //for(int i = 1; i <= n; ++i){
    //   cin >> v[i]; 
    //}

    v[1] = 2;
    v[2] = 4;
    v[3] = 7;
    v[4] = 8;
    v[5] = 10;
    v[6] = -5;
    v[7] = 2;
    v[8] = 1;

    make();
    for(int i = 1; i <= n; ++i){
        cout << Tr[i] << " ";
    }

    cout << endl;
    return 0;
}

