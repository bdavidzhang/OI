#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using tiii = tuple<int,int,int>;
using vii = vector<vector<int>>;

const int MOD = 1e9+7;

ll gcd(int a, int b){
    if(a < b) swap(a,b);
    return (b==0)?a : gcd(b, a%b);
}

ll lcm(vi &c){
   ll ans = c[0];
   for(int i = 1; i < c.size(); ++i){
        ans = ((c[i]*ans)/(gcd(ans,c[i])));
   }
   return ans;
    
}

ll binexp(ll a, ll b, ll p){
    a %= p;
    ll res = 1;
    b %= p-1;
    while(b > 0){
        if(b & 1)res = res * a % p;
        a = a * a % p;
        b >>= 1; 
    }
    return res;

}

string b10b26(int n){
    string res = "";
    while(n > 0){
        int rem = n % 26;
        char c;
        if(rem > 9){
            c = 'A' + rem - 10;
        } 
        res += c;
        n /= 26;
    }
    return res;
}

int b26b10(string s){
    int ans = 0;
    int pow = 0;
    for(int i = s.size()-1; i >= 0; ++i){
        ans += int(s[i]-'A')*(pow++);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    bool rc = false;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        int rpos = -1, cpos = -1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'R') rpos = i;
            if(s[i] == 'C') cpos = i;
        }
        if(rpos == 0){
            if(isdigit(s[rops+1]) && isdigit(s[cops+1])) 
                rc = true;
        }

        if(rc){
            string r,c;
            r = c = "";
            for(int i = rpos+1; i < cpos; ++i) r += s[i];
            for(int i = cpos+1; i < s.size(); ++i) c += s[i];
            
            int col = stoi(c);
            string C = b10b26(col); 
            cout << r << C << endl; 
        }else{
            string c,r;
            c = r = "";
            for(int i = 0;i < s.size(); ++i){
                if(isalpha(s[i])) c+=s[i];
                else r+=s[i];
            }
             
        }


    }



    return 0;
}
