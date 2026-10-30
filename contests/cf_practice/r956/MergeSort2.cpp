#include<vector>
#include<iostream>

void Merge(std::vector<int>& left,std::vector<int>& right, std::vector<int>& vec);


void MergeSort(std::vector<int>& vec){
    int len = vec.size();
    if (len <= 1) return;
    int l = len/2;
    int r = len-l;
    std::vector<int> left(l),right(r);
    int i = 0, j = 0;
    for (int i =0; i < len; ++i){
        if (i < l){
            left[i] = vec[i];
        }else{
            right[j] = vec[i];
            j++;
        }
    }
    MergeSort(left);
    MergeSort(right);
    Merge(left,right,vec);
}

void Merge(std::vector<int>& left,std::vector<int>& right, std::vector<int>& vec){
    int len = vec.size();
    int llen = left.size();
    int rlen = right.size();
    int i = 0, l = 0, r = 0;
    while(l < llen && r < rlen){
        if (left[l] < right[r]){
            vec[i] = left[l];
            i++;
            l++;
        }
        else{
            vec[i] = right[r];
            i++;
            r++;
        }
    }
    while (l < llen){
        vec[i] = left[l];
        l++;
        i++;
    }
    while (r < rlen){
        vec[i] = right[r];
        r++;
        i++;
    }
     

}



int main(){
    std::vector<int> v = {2,4,1,3,5,6,8,7};

    MergeSort(v);

    for (auto x : v) std::cout<<x<<' ';
    std::cout<<'\n';
    return 0;
}



