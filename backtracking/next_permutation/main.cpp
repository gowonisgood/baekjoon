#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    //1. permutation (순열)
    int a[3] = {1,2,3};
    do {
        for(int i=0; i<3; i++) cout << a[i];
        cout << '\n';
    }while(next_permutation(a, a+3));

    //2. combination (조합)
    int b[4] = {0,0,1,1};
    do {
        for(int i=0; i<4;i++) {
            if(b[i] == 0) cout << i+1;
        }
        cout << '\n';
    }while(next_permutation(b, b+4));

    return 0;
}
