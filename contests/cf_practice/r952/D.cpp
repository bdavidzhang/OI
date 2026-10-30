#include<iostream>
#include<string>

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::string line;

    int ymin = n+1, ymax = -1, xmin=m+1, xmax=-1;

    for (int i = 0; i < n; ++i){
        std::cin>>line;
        for (int j = 0; j < m; ++j){
             if (line[i] == '#'){
                 if(ymin > i) ymin = i;
                 if(ymax < i) ymax = i;
                 if(xmin > j) xmin = j;
                 if(xmax < j) xmax = j;
             }
        }
    }

    std::cout<<(xmin+xmax)/2+1 <<' '<<(ymin+ymax)/2+1<<'\n';
 
       
}




int main(){
    int t;
    std::cin>>t;
    while(t--){

        solve();
    }


}
