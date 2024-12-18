#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second //pair에서 first, second를 줄여서 쓰기 위해서 사용

int board[502][502]=
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502];
int n = 7, m = 10; //n = 행의 수 , m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q;

    vis[0][0] = 1; // (0,0)을 방문했다고 명시
    Q.push({0,0}); //큐에 시작점인 (0,0)을 삽입.

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int dir=0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; //nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 넘어감

            if(nx<0 || nx>=n|| ny<0 || ny >=m) continue;
            if(vis[nx][ny] || board[nx][ny]!=1) continue;

            vis[nx][ny] = 1;

            Q.push({nx,ny});

        }
    }

    return 0;
}
