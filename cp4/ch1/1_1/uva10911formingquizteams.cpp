//uva 10911-forming quiz teams
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<pair>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> cords;
    string a;//names
    int cord1;
    int cord2;
    for (int i = 0; i < 2*N; ++i){
       cin >> a;
       cin >> cord1;
       cin >> cord2;
       cords.push_back(pair<cord1,cord2>);
    }

         


    return 0;
}

