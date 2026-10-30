#include<bits/stdc++.h>
using namespace std;
int main(){

    int multiple_cases;
    cin >> multiple_cases;

    for(int i = 0;i < multiple_cases; ++i){
        int n,s;
        cin >> n >> s;
        //n is number of elements
        int arr[n];
        for(int j = 0; j < n; ++j){
            cin >> arr[j];
        }
        if(s <= arr[0]){
            cout << arr[n-1] - s << endl; 
        }else if(arr[0] < s && arr[n-1] > s){
            cout << min(s-arr[0], arr[n-1]-s) + arr[n-1] - arr[0] << endl;
        }else{
            cout << s - arr[0] << endl;
        }
    }


    return 0;
}