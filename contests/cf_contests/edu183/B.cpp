#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char> s(n,'+');
        int k;
        cin >> k;
        string t;
        cin >> t;
        int start = 0;
        int end = n-1;
        int num2 = 0;
        int remlen = n;
        for(int i = 0; i < k; ++i){
            if(t[i] == '0'){s[start++] = '-'; remlen--;} 
            if(t[i] == '1'){s[end--] = '-'; remlen--;}
            if(t[i] == '2') num2++;
        }
        if(num2 == remlen){
            for(int i = start; i <= end; ++i){
                s[i] = '-';
            }
        }else{
        while(num2){
            s[start++] = '?';
            s[end--] = '?';
            num2--;
        }
    }
        for(int i = 0; i < n; ++i){
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}