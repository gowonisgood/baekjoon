#include <iostream>
#include <bits/stdc++.h>

#define X first
#define Y second
const int INF = 1e9;

bool sang_visited[1003][1003];
bool fire_visited[1003][1003];
int sang_board[1003][1003];
int fire_board[1003][1003];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int w,h;

    //0. repeat
    cin>>n;

    for (int re=0;re<n;re++) {
        //1. initialize

        cin>>w>>h;
        for (int i=0;i<h;i++){
            for (int j=0;j<w;j++){
                sang_visited[i][j] = false;
                fire_visited[i][j] = false;
                sang_board[i][j] = 0;
                fire_board[i][j] = INF; // 불 미도달 기본값
            }
        }
        string tmp;

        queue<pair<int,int>> sang_q;
        queue<pair<int,int>> fire_q;

        //1. input
        for (int i=0;i<h;i++) {
            cin>>tmp;
            for (int j=0;j<w;j++) {
                    if (tmp[j]=='#') {
                        sang_board[i][j]=-1;
                        fire_board[i][j]=-1;
                    }
                    else if (tmp[j]=='*') {
                        fire_visited[i][j] = true;
                        fire_board[i][j]= 0;
                        fire_q.push({i,j});
                    }
                    else if (tmp[j]=='@') {
                        sang_visited[i][j] = true;
                        sang_q.push({i,j});
                    }
            }
        }

        //debug
        /*for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                cout << fire_visited[i][j] << " ";
            }
            cout << endl;
        }*/


        //2-1. calculate fire
        int fire_max = 0;
        while (!fire_q.empty()) {
            pair<int, int> cur = fire_q.front(); fire_q.pop();

            for (int k=0;k<4;k++) {
                int nx = cur.X + dx[k];
                int ny = cur.Y + dy[k];

                if (nx<0||nx>=h || ny<0||ny>=w) continue;
                if (fire_board[nx][ny]==-1||fire_visited[nx][ny]==true) continue;

                fire_visited[nx][ny]=true;
                fire_board[nx][ny] = fire_board[cur.X][cur.Y]+1;
                fire_max = max(fire_max, fire_board[nx][ny]);
                fire_q.push({nx,ny});
            }
        }

        //2-2. calculate sang
        bool is_escaped = false;
        int sang_max = 0;
        int answer = -1;
        while (!sang_q.empty()&& answer == -1) {
            //cout << "called\n"; //debug
            pair<int, int> cur = sang_q.front(); sang_q.pop();

            for (int k=0;k<4;k++) {
                int nx = cur.X + dx[k];
                int ny = cur.Y + dy[k];
                int nt = sang_board[cur.X][cur.Y] + 1;

                if (nx<0||nx>=h || ny<0||ny>=w) {
                    answer = nt;
                    break;
                }
                if (sang_board[nx][ny]==-1||sang_visited[nx][ny]==true||nt>=fire_board[nx][ny]) continue;

                sang_visited[nx][ny]=true;
                sang_board[nx][ny] = nt;
                //cout << sang_board[nx][ny] <<"\n"; //debug
                sang_max = max(sang_max, sang_board[nx][ny]);
                //cout << "sang_max: "<< sang_max <<"\n"; //debug
                sang_q.push({nx,ny});
            }
        }



        /* debug */
        //cout <<"fire_max: "<< fire_max << endl;
        //cout <<"sang_max: "<< sang_max << endl;
        /* debug */

        if (answer==-1) cout << "IMPOSSIBLE\n";
        else cout << answer<< '\n';


    }



    return 0;
}