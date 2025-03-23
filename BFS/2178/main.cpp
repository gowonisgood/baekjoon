/*#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[102][102];
int dis[102][102];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin>>n>>m;

    int num = 0;
    for(int i=0;i<n;i++) {
        cin >> num;
        for(int j=m-1;j>=0;j--) {
            board[i][j] = num % 10;
            //cout << num % 10;
            num /= 10;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            dis[i][j]=-1;
        }
    }

    queue<pair<int,int>> Q;
    Q.push({0,0});

    dis[0][0] = 0;

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();

        for(int i=0;i<4;i++) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x<0||x>=n||y<0||y>=m) continue;
            if(board[x][y]==0||dis[x][y]>=0) continue;
            dis[x][y] = dis[cur.X][cur.Y]+1;
            Q.push({x,y});
        }
    }

    cout << dis[n-1][m-1];

    return 0;
}*/

#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[102][102];
int dis[102][102];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin>>n>>m;

    string num = "0";
    for(int i=0;i<n;i++) {
        cin >> num;
        for(int j=0;j<m;j++) {
            board[i][j] = num[j]- '0';
        }
    }



    queue<pair<int,int>> Q;
    Q.push({0,0});

    dis[0][0] = 1;

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();

        for(int i=0;i<4;i++) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x<0||x>=n||y<0||y>=m) continue;
            if(board[x][y]==0||dis[x][y]>0) continue;
            dis[x][y] = dis[cur.X][cur.Y]+1;
            Q.push({x,y});
        }
    }

    cout << dis[n-1][m-1];

    return 0;
}
