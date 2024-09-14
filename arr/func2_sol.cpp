//
// Created by gowon on 2024-09-14.
//
#include <iostream>
using namespace std;

int freq[100]={0,};

int func1(int arr[],int N) {
    for(int i=0;i<N;i++) {
        if(freq[100-arr[i]]==1) return 1;
        freq[arr[i]] = 1;
    }
    return 0;
}

int main() {
    int N;
    cin>>N;
    int arr[N];

    for (int i=0;i<N;i++) {
        int a = 0;
        cin>>a;
        arr[i] = a;
    }
    cout << func1(arr,N);

    return 0;
}
