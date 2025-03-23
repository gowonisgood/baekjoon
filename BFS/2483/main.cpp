#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int m,n,k;

int board[102][102];
int dis[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;

    int x1,y1;
    int x2,y2;

    for(int rec=0;rec<k;rec++) {
        cin >> x1 >> y1 >> x2 >> y2;
        //cout << m-y2 <<" " << m-y1 << "\n";

        for(int i=m-y2;i<(m-y1);i++) {
            for(int j=x1;j<x2;j++) {
                board[i][j] =1;
            }
        }
    }

    /*for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(board[i][j]==1) cout << "(" <<i<<","<<j<<")\n";
        }
    }*/
    queue<pair<int,int>> Q;

    int cnt = 0;
    //int size[k+2] = {0,};
    vector<int> sizee;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(board[i][j]==0 && dis[i][j]==0) {
                //size[cnt] =
                dis[i][j] = 1;
                //cnt ++;
                Q.push({i,j});
                int size_entry = 1;
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int d=0;d<4;d++) {
                        int nx = cur.X + dx[d];
                        int ny = cur.Y + dy[d];
                        if(nx<0||ny<0||nx>=m||ny>=n) continue;
                        if(board[nx][ny]==1||dis[nx][ny]!=0) continue;

                        dis[nx][ny] =1; size_entry++;
                        Q.push({nx,ny});
                    }
                }
                sizee.push_back(size_entry);
                cnt++;
                //TODO : size, cnt
            }
        }
    }



    cout << cnt << "\n";
    sort(sizee.begin(),sizee.end());
    for(int i=0;i<cnt;i++) cout << sizee[i] << " ";
    return 0;
}
