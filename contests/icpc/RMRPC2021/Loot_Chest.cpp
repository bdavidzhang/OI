#include<bits/stdc++.h>
using namespace std;

int DW, DL;
double G, L;
double E[101];

int main(){
    cin >> DL >> DW >> G >> L;
    G *= 0.01; L *= 0.01;
    E[100] = 1/(1-L);
    for(int j = 99; j >= 0; --j){
        E[j] = 1 + L * E[min(100,j+DL)] + (1-L) * (1-j*0.01) * E[min(100,j+DW)];
    }
    cout << fixed << setprecision(20) << E[0] / G << endl;

    return 0;
}