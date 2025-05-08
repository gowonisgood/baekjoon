#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int board[65][65];

string answer;

//2025년 5월 8일: 최적화된 isSame 함수 - 첫칸을 기준으로 모든 칸과 비교
bool isSame(int board[][65], int n, int r, int c) {
    int value = board[r][c];
    for(int i=r;i<r+n;i++) {
        for(int j=c;j<c+n;j++) {
            if(value!=board[i][j]) return false;
        }
    }
    return true;
}

void quadtree(int board[][65], int n, int r, int c) {

    if(!isSame(board,n,r,c)) {
        answer += "(";
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                quadtree(board,n/2,r+i*(n/2),c+j*(n/2));

            }
        }
        answer += ")";
    }else {
        //answer += "(";
        if(board[r][c]==0) answer+="0";
        else if(board[r][c]==1) answer+="1";
        return;
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;


    for(int i=0;i<N;i++) {
        string input;
        cin >> input;
        for(int j=0;j<N;j++) {
            board[i][j] = input[j]-'0';
        }
    }

    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<N;j++) {
    //         cout << board[i][j];
    //     }
    //     cout <<"\n";
    // }

    quadtree(board,N,0,0);
    cout << answer;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
