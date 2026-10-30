//longest increasing subsequence O(nlogn)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    vector<int> tails;
    for(int num : v){
        vector<int>::iterator it = lower_bound(tails.begin(),tails.end(),num); 
        if(it == tails.end()){
            tails.push_back(num); 
        }else{
           *it = num; 
        }
    }

    cout << tails.size() << endl;

    return 0;
}
