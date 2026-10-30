#include<iostream>
#include<string>

int main(){
    int t;
    std::cin>>t;
    while(t--){
    std::string a,b;
    std::cin>>a>>b;
        char x,y;
        x = a[0];
        y=b[0];
        a[0] = y;
        b[0] = x; 
        std::cout<<a << ' '<<b<<'\n';
    }
   
    return 0;
}
