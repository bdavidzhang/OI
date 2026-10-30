#include<iostream>
#include<vector>

int main(){

    int S,N;

    std::cin>>S>>N;

    std::vector<bool> slots(S+1);

    slots[0] = true;

    for(int i = 0 ;i< N;++i){
        int a;
        std::cin>> a;
        if(a == 1){
            slots[1] = true;
            slots[2] = true; 
            slots[S] = true;
        }else if(a == S){
            slots[S] = true;
            slots[1] = true;
            slots[S-1] = true;
        }else{
            slots[a-1] = true;
            slots[a+1] = true;
            slots[a] = true; 
        }
    }

    int cnt = 0;
    for(int i = 1; i <S+1; ++i){
        if(slots[i] == false){
            if(i == 1){
                slots[1] = true;
                slots[S] = true;
                slots[2] = true; 
                cnt++;
            }else{
                slots[i] = true;
                slots[i+1] = true;
                slots[i-1] = true; 
                cnt++;
            }
        }             
    }

    std::cout<<cnt<<std::endl;

    return 0;

}
