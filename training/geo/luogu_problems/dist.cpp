#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int x[maxn],y[maxn];//读入的三个数组
double dist(int x1,int y1,int x2,int y2){//求距离的函数
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));//公式
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> y[i];
    }

    double min_dist = 1e10;
    for(int i = 0; i < n-1; ++i){
        for(int j = i + 1; j < n; ++j){
            cout << i << j << endl;
            min_dist = min(min_dist, dist(x[i], y[i], x[j], y[j]));
        }
    }

    printf("%.4f", min_dist);

    return 0;
}