#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool vis[512][512];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // queue<pair<int,int>> Q;
    // Q.push({0,0});

    int n,m;

    cin >> n;
    cin >> m;

    int board[n+1][m+1] = {0,};
    //vector<vector<int>> board(n, vector<int>(m, 0));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>board[i][j];
        }
    }

    int max_area = 0;
    int cnt = 0;
    for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==1&&vis[i][j]==0) {
                    cnt++;
                    queue<pair<int,int>> Q;
                    Q.push({i,j});
                    vis[i][j] = true;

                    int sum=1;

                    while(!Q.empty()) {
                        pair<int,int> cur = Q.front(); Q.pop();
                        for(int dir=0; dir<4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx<0||nx>=n||ny<0||ny>=m) continue;
                            if(vis[nx][ny] || board[nx][ny]!=1) continue;
                            vis[nx][ny] = true;
                            Q.push({nx,ny});

                            sum++;
                        }
                    }
                    if(sum>max_area) max_area = sum;
                }
            }
        }

    cout << cnt << "\n" << max_area << endl;
    return 0;
}
