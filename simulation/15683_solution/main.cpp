#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board1[10][10];
int board2[10][10];

vector<pair<int,int>> cctv;

int n,m;

bool OOB(int x, int y) {
    if(x<0||x>=n||y<0||y>=m) return true;
    return false;
}

void upd(int x,int y,int dir) {
    dir = dir % 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(OOB(x,y)||board2[x][y]==6) return;
        if(board2[x][y]!=0) continue;
        board2[x][y]=7;
    }

}
int main() {
    cin >> n >> m;
    int mn = 0; //mn 변수도 업데이트 필요 - cctv 아예 없는 경우도 고려

    //1. input
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board1[i][j];

            if(board1[i][j]!=0 && board1[i][j]!=6) {
                cctv.push_back({i,j});

            }else if(board1[i][j]==0){
                mn++;
            }

        }
    }

    //2. calculate
    for(int tmp=0;tmp<(1<<(2*cctv.size()));tmp++) {
        //매 반복마다 board2 초기화
        memcpy(board2,board1,sizeof(board2));

        int brute = tmp;
        int val = 0;
        //cctv 배열 활용
        for(int i=0;i<cctv.size();i++) {
            int dir = brute%4;
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;

                if(board1[x][y]==1) {
                    upd(x,y,dir);
                }
                else if(board1[x][y]==2) {
                    upd(x,y,dir);
                    upd(x,y,dir+2);
                }
                else if(board1[x][y]==3) {
                    upd(x,y,dir);
                    upd(x,y,dir+1);
                }
                else if(board1[x][y]==4) {
                    upd(x,y,dir);
                    upd(x,y,dir+1);
                    upd(x,y,dir+3);
                }
                else if(board2[x][y]==5) {
                    upd(x,y,dir);
                    upd(x,y,dir+1);
                    upd(x,y,dir+2);
                    upd(x,y,dir+3);
                }

        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board2[i][j]==0) val ++;
            }
        }

        /* debug */
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout << board2[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        /* debug */

        mn = min(mn,val);
    }

    /* debug */
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << board2[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    /* debug */


    cout << mn;

    return 0;
}
