#include <iostream>
#include <bits/stdc++.h>

#define X first
#define Y second

int vis[512][512];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[26][26];

int cnt = 0; /* total danji */
int cnt_cnt[626];

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
            string st;
            cin >> st;
            for(int j=0;j<n;j++) {
                board[i][j] = st[j] - '0';
                //cout << board[i][j];
            }
        //cout <<"\n";
    }



    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(board[i][j]==1&&vis[i][j]==0) {
                cnt ++; /* total dangi */
                cnt_cnt[cnt-1] = 1;
                queue<pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});

                while(!Q.empty()) {
                    pair<int,int> cur = Q.front();
                    Q.pop();

                    for(int d=0; d<4; d++) {
                        int nx = cur.X + dx[d];
                        int ny = cur.Y + dy[d];

                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(vis[nx][ny]||board[nx][ny]==0) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                        cnt_cnt[cnt-1]++;

                    }
                }
            }
        }

    }
    //std::cout << "Hello, World!" << std::endl;

    sort(cnt_cnt,cnt_cnt+cnt);

    cout << cnt;
    for(int i=0;i<cnt;i++) {
        cout <<"\n"<<cnt_cnt[i];
    }
    return 0;
}
