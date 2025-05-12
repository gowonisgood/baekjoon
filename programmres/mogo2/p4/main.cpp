#include <string>
#include <vector>
#include <bits/stdc++.h>

//튜플 사용 방법
// tuple<int, int, int> t = make_tuple(1, 2, 3);
// int a = get<0>(t); // 첫 번째
// int b = get<1>(t); // 두 번째
// int c = get<2>(t); // 세 번째 ← "third" 대응


#define X first
#define Y second

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int board[1000][1000][2];
int visited[1000][1000][2];


using namespace std;

int solution(int n, int m, vector<vector<int>> hole) {


    //int answer = 0;
    //queue<pair<int,int>> Q ;

    queue<tuple<int,int,int>> Q;

    visited[m-1][0][0] = -1;
    visited[m-1][0][1] = -1;
    Q.push({m-1,0,0});

    int realN = 0;
    int realM = n-1;

    for(int r=0;r<hole.size();r++){
        int i =  m - hole[r][1];
        int j = hole[r][0] - 1;
        //board[i][j] = 1;
        visited[i][j][0] = -1;
        visited[i][j][1] = -1;
    }

    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << visited[i][j];
        }
        cout << "\n";
    }*/


    while(!Q.empty()){

        //pair<int,int> cur = Q.front();
        //if(cur.X==realN && cur.Y==realM) return board[cur.X][cur.Y];
        tuple<int,int,int> cur = Q.front();
        int curX = get<0>(cur);
        int curY = get<1>(cur);
        int used = get<2>(cur);
        if(curX==realN && curY==realM) return board[curX][curY][used];
        Q.pop();

        for(int d=0;d<4;d++){
            //서로 동시에 관리됨으로 동시에 진행 해도 상관 X
                int nx = curX + dx[d];
                int ny = curY + dy[d];

                if(nx<0||nx>=m||ny<0||ny>=n) continue;
                if(visited[nx][ny][used]==1||visited[nx][ny][used]==-1) continue;
                visited[nx][ny][used] = 1;
                Q.push({nx,ny,used});

                board[nx][ny][used] = board[curX][curY][used]+1;

            if(used==0){ //신비한 신발 이동
                 int nx = curX + dx[d]*2;
                int ny = curY + dy[d]*2;

                if(nx<0||nx>=m||ny<0||ny>=n) continue;
                if(visited[nx][ny][1]==1) continue;
                visited[nx][ny][1] = 1;
                Q.push({nx,ny,1});

                board[nx][ny][1] = board[curX][curY][0]+1;
            }


        }

        /*debug*/
        //  for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout << board[i][j];
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        /*debug*/

    }


    return -1;
}

/*#include <string>
#include <vector>
#include <bits/stdc++.h>


#define X first
#define Y second

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int board[1000][1000];
int visited[1000][1000];


using namespace std;

int solution(int n, int m, vector<vector<int>> hole) {


    //int answer = 0;
    queue<pair<int,int>> Q ;

    visited[m-1][0] = 1;
    Q.push({m-1,0});

    int realN = 0;
    int realM = n-1;

    for(int r=0;r<hole.size();r++){
        int i =  m - hole[r][1];
        int j = hole[r][0] - 1;
        //board[i][j] = 1;
        visited[i][j] = 1;
    }

    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << visited[i][j];
        }
        cout << "\n";
    }*/


    while(!Q.empty()){

        pair<int,int> cur = Q.front();
        if(cur.X==realN && cur.Y==realM) return board[cur.X][cur.Y]-1;

        Q.pop();

        for(int d=0;d<4;d++){
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];

            if(nx<0||nx>=m||ny<0||ny>=n) continue;
            if(visited[nx][ny]==1) continue;
            visited[nx][ny] = 1;
            Q.push({nx,ny});

            board[nx][ny] = board[cur.X][cur.Y]+1;

            if(nx==realN&&ny==realM) return board[nx][ny]-1;
        }

        /*debug*/
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << board[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
        /*debug*/

    }


    return -1;
}*/