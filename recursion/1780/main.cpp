#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[2190][2190];
int mone=0;
int zero=0;
int pone=0;

bool isSame(int board[][2190], int n, int r, int c) {

    int f = 0;
    int s = 0;


    for(int i=r;i<r+n;i++) {
        for(int j=c;j<c+n-1;j++) {
            f = board[i][j];
            s = board[i][j+1];
            if(f!=s) {
                return false;
            }
        }
    }

    for(int i=r;i<r+n-1;i++) {
        for(int j=c;j<c+n;j++) {
            f = board[i][j];
            s = board[i+1][j];
            if(f!=s) {
                return false;
            }
        }
    }

    return true;
}

void paper(int board[][2190], int n, int r, int c) {

    int three_cut = n/3;

    if(!(isSame(board,n,r,c))) {
        paper(board,n/3,r,c);
        paper(board,n/3,r,c+three_cut);
        paper(board,n/3,r,c+2*three_cut);

        paper(board,n/3,r+three_cut,c);
        paper(board,n/3,r+three_cut,c+three_cut);
        paper(board,n/3,r+three_cut,c+2*three_cut);

        paper(board,n/3,r+2*three_cut,c);
        paper(board,n/3,r+2*three_cut,c+three_cut);
        paper(board,n/3,r+2*three_cut,c+2*three_cut);
    }else {
        if(board[r][c]==-1) mone++;
        else if(board[r][c]==0) zero++;
        else if(board[r][c]==1) pone++;
        return;
    }
    return;
}

int main()
{
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

    cout << mone <<"\n";
    cout << zero <<"\n";
    cout << pone <<"\n";



    return 0;
}

/* GPT.cpp */

/* #include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> A;
int cnt[3]; // cnt[0] for -1, cnt[1] for 0, cnt[2] for 1

// (x, y)를 왼쪽 위로 하는 size x size 영역을 검사
void solve(int x, int y, int size) {
    int first = A[x][y];
    bool same = true;
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (A[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }
    if (same) {
        // 값이 -1, 0, 1 중 하나이므로 인덱스 변환
        cnt[first + 1]++;
    } else {
        int s = size / 3;
        for (int dx = 0; dx < 3; ++dx) {
            for (int dy = 0; dy < 3; ++dy) {
                solve(x + dx * s, y + dy * s, s);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.assign(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    // 초기 카운트 0
    cnt[0] = cnt[1] = cnt[2] = 0;

    solve(0, 0, N);

    // 출력: -1, 0, 1 순
    cout << cnt[0] << "\n";
    cout << cnt[1] << "\n";
    cout << cnt[2] << "\n";

    return 0;
}
*/