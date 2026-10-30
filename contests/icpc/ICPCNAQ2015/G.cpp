#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n; ++i) cin >> v[i];
    sort(v.begin(),v.end());

    //for(auto x : v) cout << x << " ";    
    //cout << endl;
    long long sum = 0;

    if(n % 2 == 0){
       for(int j = n-1; j >= 2; j -= 2){
            int opt1 = v[0]+2*v[1]+v[j];
            int opt2 = v[0]*2+v[j]+v[j-1];
            sum += (opt1 < opt2) ? opt1 : opt2;
       }
       sum += v[1];
    }else{
        for(int j  = n-1; j >= 3; j -= 2){
            int opt1 = v[0]+2*v[1]+v[j];
            int opt2 = v[0]*2+v[j]+v[j-1];

            sum += (opt1 < opt2) ? opt1 : opt2;

        }
        sum += v[0] + v[1] + v[2];
    }

    cout << sum << endl;

    return 0;
}
