#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int n,m;
int board[1001][1001];
int dis[1001][1001];

queue<pair<int,int>> Q;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
    cin >> m;
    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
            if(board[i][j]==1) {
                dis[i][j]++;
                Q.push({i,j});
                //cout << i << " " << j << "\n";
            }
        }
    }




    int max = 0;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]!=0||dis[nx][ny]>0) continue;

            //큐에 넣어야하는 경우
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            if(max<dis[nx][ny]) max = dis[nx][ny];
            Q.push({nx,ny});
            //cout << "(" <<nx <<", " << ny << ")"; //확인용 코드
        }
        //cout << "\n"; //확인용 코드
    }



    //토마토가 다익었는지 확인 (갇혀서 토마토가 다 익을 수 없는 경우)

    for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
            if(board[i][j]==0 && dis[i][j] ==0) {
                //cout << "\nboard[i][j]: " << board[i][j] << "dis[i][j]:: " << dis[i][j]<<"\n";
                cout << -1;
                return 0;
            }
        }
    }

    if(max==0) { //토마토가 처음부터 다익어 있던경우
        cout << 0;
    }else {
        cout << max-1;
    }

    //TODO:처음부터 토마토가 다 익어있는 경우 (만약 dis의 최댓값이 1 이면 처음부터 다 익어 있는 상황, 원래 대로라면 최댓값 -1 출력 ㄱㄱ)




    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
