#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int N;
int board[22][22];

void move(int dir){
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            board[i][j] += board[i+1][j+1];
        }
    }
}

bool OOB(int x, int y) {
    if(x<0||y<0||x>=N||y>=N) return true;
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //1. input
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
        }
    }

    //2. calculate
    int re = 5;
    while(re--) {
        for(int dir=0;dir<4;dir++) {

        }
    }



    return 0;
}
