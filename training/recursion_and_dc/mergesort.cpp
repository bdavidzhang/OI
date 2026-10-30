#include<iostream>
#include<template>
#include<vector>

template <typename T> 
void merge_sort (vector<T> a, int front, int end){
    if (front >= end) return;
    int mid = front + (end-front)/2;
    merge_sort(a, front, mid);
    merge_sort(a, mid,end);
    merge(a, front, mid, end);
}

template <typename T>
void merge(vector<T> a, int front, int mid, int end){
    
    //todo:implement merge part


}
