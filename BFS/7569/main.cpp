#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[102][102][102];
int day[102][102][102];
int visited[102][102][102];
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,H;
    cin>>M>>N>>H;

    bool zero_flag = true;
    queue<tuple<int, int, int>> Q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin>>board[i][j][k];
                if (board[i][j][k] == 0) { zero_flag = false;}
                if (board[i][j][k] == 1) {
                    visited[i][j][k] = 1;
                    Q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    if (zero_flag) {
        cout << 0;
        return 0;
    }



    int mday = 0;
    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front(); Q.pop();

        for (int d=0; d<6; d++) {
            //왼쪽부터 세는 인덱스
            int nx = get<2>(cur) + dx[d];
            int ny = get<1>(cur) + dy[d];
            int nz = get<0>(cur) + dz[d];

            if (nx<0||ny<0||nz<0||nx>=M||ny>=N||nz>=H) continue;
            if (board[nz][ny][nx]==-1||visited[nz][ny][nx]) continue;

            visited[nz][ny][nx] = 1;
            board[nz][ny][nx] = 1;
            day[nz][ny][nx] = day[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            if (day[nz][ny][nx]>=mday) mday = day[nz][ny][nx];
            Q.push({nz,ny,nx});

        }
    }




    //TODO: 순회 후 0 이 하나도 없어야함
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                //cout<<day[i][j][k]<<" "; //debug
                if (board[i][j][k] == 0) {
                    mday = -1;
                }
            }
            //cout<<"\n"; //debug
        }
        //cout<<"\n"; //debug
    }

    cout<<mday;


    return 0;
}