/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };

int n=7, m=10;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int vis[512][512];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();

        for(int i=0;i<4;i++) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x<0||x>n||y<0||y>m) continue;
            if(board[x][y]==0||vis[x][y]==1) continue;

            cout << " X: " << x << " Y: " << y ;
            vis[x][y] = 1;
            Q.push({x,y});
        }

        cout<<"\n";
    }

}*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int vis[512][512];

int n=7, m=10;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0;i<4;i++) {
            int x = cur.X+dx[i];
            int y = cur.Y+dy[i];

            if(x<0||x>n||y<0||y>m) continue;
            if(board[x][y]==0||vis[x][y]==true) continue;

            cout << x << " " << y << "\n";
            vis[x][y] = 1;
            Q.push({x,y});
        }
    }



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
