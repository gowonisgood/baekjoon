#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[102][102];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
bool visited[102][102];

int main() {
    int n;
    cin >> n;

    int max = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> board[i][j];
            if(max<board[i][j]) max = board[i][j];
        }
    }

    int max_cnt = 0;
    for(int height=0; height<max; height++) {
        queue<pair<int,int>> Q;
        pair<int,int> base;
        for(int i=0; i<n; i++) {
           for(int j=0; j<n; j++) {
               visited[i][j] = 0;
           }
       }
        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {

                if(board[i][j]>height&&(!visited[i][j])) {
                    base = {i,j};
                    visited[i][j] = 1;
                    Q.push(base);
                    cnt++;

                    while(!Q.empty()){
                        pair<int,int> cur = Q.front();
                        Q.pop();

                        for(int d=0;d<4;d++) {
                            int x = cur.X + dx[d];
                            int y = cur.Y + dy[d];
                            if(x<0||x>=n||y<0||y>=n) continue;
                            if(board[x][y]<=height||visited[x][y]) continue;
                            visited[x][y]=1;
                            Q.push({x,y});
                        }

                    }
                }
            }
        }

        if(max_cnt<cnt) max_cnt = cnt;
    }


    cout << max_cnt;
    return 0;
}



/*
#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[102][102];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
bool visited[102][102];

int main() {
int n;
cin >> n;

int max = 0;
for(int i=0;i<n;i++) {
for(int j=0;j<n;j++) {
cin >> board[i][j];
if(max<board[i][j]) max = board[i][j];
}
}

int max_cnt = 0;
for(int height=0; height<max; height++) {

//pair<int,int> base;
for(int i=0; i<n; i++) {
for(int j=0; j<n; j++) {
visited[i][j] = 0;
}
}
int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

            if(board[i][j]>height&&(!visited[i][j])) {
                queue<pair<int,int>> Q;
                visited[i][j] = 1;
                Q.push({i,j});
                cnt++;

                while(!Q.empty()){
                    pair<int,int> cur = Q.front();
                    Q.pop();

                        for(int d=0;d<4;d++) {
                            int x = cur.X + dx[d];
                            int y = cur.Y + dy[d];
                            if(x<0||x>=n||y<0||y>=n) continue;
                            if(board[x][y]<=height||visited[x][y]) continue;
                            visited[x][y]=1;
                            Q.push({x,y});
                        }

                    }
                }
            }
        }

        if(max_cnt<cnt) max_cnt = cnt;
    }


    cout << max_cnt;
    return 0;
}*/
