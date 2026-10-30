#include<algorithm>
#include<vector>
#include<tuple>
#include<string>
#include<iostream>

bool compareage(int a, int b){
    return a > b;
    //descending
}

bool comparelname(std::string a, std::string b){
    return a > b;
}

bool comparefname(std::string a, std::string b){
    return b > a;
}

bool tcompareage(std::tuple<int, std::string, std::string> x, std::tuple<int, std::string, std:: string>y){
    return compareage(std::get<0>(x),std::get<0>(y));
}


bool tcomparelname(std::tuple<int, std::string, std::string> x, std::tuple<int, std::string, std:: string>y){
    return comparelname(std::get<1>(x),std::get<1>(y));
}

bool tcomparefname(std::tuple<int, std::string, std::string> x, std::tuple<int, std::string, std:: string>y){
    return comparefname(std::get<2>(x),std::get<2>(y));
}


int main(){

    std::vector<std::tuple<int,std::string,std::string>> v;

    std::tuple<int,std::string,std::string> a(1,"A","Ruba");
    std::tuple<int,std::string,std::string> b(20,"B","Ryan");
    std::tuple<int,std::string,std::string> c(15, "C", "California");
    std::tuple<int,std::string,std::string> d(12,"D", "DJ");
    std::tuple<int,std::string,std::string> e(19, "X", "EDM");

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    std::sort(v.begin(),v.end(),tcompareage);

    for (auto x : v){
        std::cout << std::get<0>(x) << std::endl;
    }

    std::sort(v.begin(),v.end(),tcomparelname);

    for (auto x : v){
        std::cout << std::get<1>(x) << std::endl;
    }

    std::sort(v.begin(),v.end(),tcomparefname);

    for (auto x : v){
        std::cout << std::get<2>(x) << std::endl;
    }


    return 0;

}
