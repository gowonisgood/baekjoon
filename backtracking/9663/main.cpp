#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int cnt;
int N;
bool isused1[40];
bool isused2[40];
bool isused3[40];



void queen(int k) {
    if(k==N) {
        cnt++;
        return;
    }
    for(int i=0;i<N;i++) {
            if((!isused1[i])&&(!isused2[i+k])&&(!isused3[k-i+N-1])) {

                isused1[i]=true;
                isused2[i+k]=true;
                isused3[k-i+N-1]=true;
                queen(k+1);
                isused1[i]=false;
                isused2[i+k]=false;
                isused3[k-i+N-1]=false;
            }
        }
    }



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;

    //std::cout << "Hello, World!" << std::endl;
    queen(0);
    cout << cnt;
    return 0;
}
