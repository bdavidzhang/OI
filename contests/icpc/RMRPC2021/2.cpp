#include<iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a;
    std::cin>> a;
    std::cout<<static_cast<double>(100)/a<<std::endl
        <<static_cast<double>(100)/(100-a)<<std::endl;


    return 0;
}
