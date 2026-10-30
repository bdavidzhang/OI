//help a phd!
#include<cstdio>
#include<string>
#include<iostream>
int main(){
    std::string s;
    std::string a="0",b="0";
    int sum = 0,t;
    bool flag = true;
    std::cin >> t;
    //printf("%d\n",t);
    while (t--){
        sum = 0;
        a = "";b = "";
        std::getline(std::cin,s);
        //printf("%s\n",s.c_str());
        if(s.compare("P=NP") == 0) printf("skipped\n");
        else{
           for(char c: s){
              if(flag && c != '+'){
                  a += c;
              }
              else if ( c == '+') flag = false;
              else if(!flag && c != '+'){
                  b += c;
              }
           }
           sum += std::stoi(a);
           sum += std::stoi(b);
           printf("%d\n",sum);
        }
   }
    return 0; 
}
              
            

