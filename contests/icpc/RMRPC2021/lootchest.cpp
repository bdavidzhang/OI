#include<bits/stdc++.h>
using namespace std;


int main(){
    int DW,DL;
    cin >> DL >> DW;
    double gain,lose;
    cin >> gain >> lose;
    gain *= 0.01; lose *= 0.01;
    double win = 1-lose;

    double em[101];
    em[100] = 1/win;

    for(int i = 99; i >= 0; --i){
        em[i] = 1 + lose * em[min(100,i+DL)] + win * (1-i*0.01) * em[min(100,i+DW)];
    }

    cout <<  fixed <<  setprecision(20) <<em[0] / gain << endl;

    return 0;
}