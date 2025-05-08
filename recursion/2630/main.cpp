#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int blue;
int white;

int board[130][130];

bool isSame(int board[][130], int n, int r, int c) {
    for(int i=r;i<r+n;i++) {
        for(int j=c;j<c+n-1;j++) {
            if(board[i][j]!=board[i][j+1]) return false;
        }
    }

    for(int i=r;i<r+n-1;i++) {
        for(int j=c;j<c+n;j++) {
            if(board[i][j]!=board[i+1][j]) return false;
        }
    }

    return true;

}

void paper(int board[][130], int n, int r, int c) {

    if(!(isSame(board,n,r,c))) {
        paper(board,n/2,r,c);
        paper(board,n/2,r,c+(n/2));
        paper(board,n/2,r+(n/2),c);
        paper(board,n/2,r+(n/2),c+(n/2));

    }else {
        if(board[r][c]==1) blue++;
        else if(board[r][c]==0) white++;
        return;
    }
    return;

}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
        }
    }

    paper(board,N,0,0);

    cout << white <<"\n";
    cout << blue <<"\n";



    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
