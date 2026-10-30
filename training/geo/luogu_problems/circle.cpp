#include<bits/stdc++.h>
using namespace std;

double x[60],y[60],r[60];
double x1,y1,x2,y2;

double dist(double a,double b,double z,double w){
    return sqrt((a-z)*(a-z) + (b-w)+(b-w));
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ;i < n; ++i) cin >> x[i]; 
    for(int i = 0 ;i < n; ++i) cin >> y[i];
    for(int i = 0 ;i < n; ++i) cin >> r[i];
    cin >> x1 >> y1 >> x2 >> y2;

    int cnt = 0;
    for(int i = 0 ;i < n; ++i){
        bool flag1 = dist(x1,y1,x[i],y[i]) <= r[i];
        bool flag2 = dist(x2,y2,x[i],y[i]) <= r[i];

        if(flag1 ^ flag2) cnt++;
    }

    cout << cnt << endl;


    return 0;
}