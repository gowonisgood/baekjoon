#include <iostream>
#include <bits/stdc++.h>

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int board[52][52];
int N;
using namespace std;
int m,n,k;

queue<pair<int,int>> Q;
int vis[52][52];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin  >> N;

    for(int repeat=0; repeat<N; repeat++) {
        //TODO: 보드를 항상 다시 0으로 초기화 , vis도 다시 0으로 초기화 , 큐는 초기화 안해도 됨

        cin >> m >> n >> k;

        //1. 입력받기
        int a=0, b=0;
        for(int i=0;i<k;i++) {
            cin >> a >> b;
            board[b][a] = 1;
        }

        /*for(int i=0;i<n;i++) {
            for(int j=0; j<m;j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }*/ //디버깅용

        //2. bfs
        int worm = 0;
        for(int i=0;i<n;i++) {
            for(int j=0; j<m;j++) {
                if(board[i][j]==1&&vis[i][j]==0) {
                    worm ++;
                    Q.push({i,j});
                    //cout << "(" << i << "," << j << ")\n"; //디버깅용
                }

                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int d=0;d<4;d++) {
                        int nx = cur.X + dx[d];
                        int ny = cur.Y + dy[d];

                        if(nx<0||nx>=n||ny<0||ny>m) continue;
                        if(board[nx][ny]==0||vis[nx][ny]==1) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }


                }
            }
        }

        cout << worm <<"\n";
        for(int i=0;i<52;i++) {
            for(int j=0;j<52;j++) {
                board[i][j] =0;
                vis[i][j] =0;
            }
        }

    }



    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
