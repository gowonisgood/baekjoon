#include <iostream>
#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
int n,m; //노트북의 가로, 세로
int k; //스티커의 개수

int cnt; //붙인 스티커의 개수

int board1[42][42];
int board2[42][42];

bool OOB(int x,int y) {
    if(x<0||y<0||x>=n||y>=m) return true;
    return false;
}

vector<vector<int>> rotateSticker(const vector<vector<int>>& src) {
    int R = src.size();
    int C = src[0].size();
    vector<vector<int>> rotated(C,vector<int>(R));
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            rotated[j][R-1-i] = src[i][j];
        }
    }
    return rotated;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    cin >> k;

    for(int sti=0;sti<k;sti++) {
        //1. input
        //1-1. 스티커 크기 입력
        int r,c;
        cin >> r >> c;
        vector<vector<int>> sticker(r,vector<int>(c));

        //1-2. 스티커 값 입력받기
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin >> sticker[i][j];
            }
        }

        //1.스티커를 붙일 수 있는 위치를 찾는다 (붙일 수 있는 한 가장 왼쪽 위)
        //2. 붙일 수 없으면 90도 회전후 ^ 위 과정 반복 (4번)

        //0.bfs로 풀 수 있을 거 같음
        //1.스티커를 붙인칸은 1로 표기후

        //2. 노트북에 붙일 수 있는가?
        bool find_flag = false;
        int nx,ny;
        for(int rota=0;rota<4;rota++) {
            for(int i=0;i<n;i++) {
                if(find_flag) break;
                for(int j=0;j<m;j++) {
                    bool isNotStick = false;
                    memcpy(board2,board1,sizeof(board1));
                    for(int ii=0;ii<r;ii++) {
                        for(int jj=0;jj<c;jj++) {

                            if(sticker[ii][jj]==1) {
                                nx = i + ii;
                                ny = j + jj;



                                if(OOB(nx,ny)||board1[nx][ny]==1) {
                                    isNotStick=true;
                                    break;
                                }
                                board2[nx][ny] = 1;
                            }
                        }
                        if(isNotStick) break;
                    }

                    if(!isNotStick) {
                        find_flag = true;
                        memcpy(board1,board2,sizeof(board1));
                        break;
                    }

                }
            }
            if(find_flag) break;
            sticker = rotateSticker(sticker);
            //r,c를 바꿔줘야함
            swap(r,c);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board1[i][j]==1) cnt++;
        }
    }

    cout << cnt;
    return 0;
}
/* 깨달은 점*/
// 1. 배열 돌리기 (수직으로) + r,c 크기 바뀌는거 주의
// 2. break 부분 flag 써서 처리하는 부분 다시 보기 -> 더 좋은 방법 있으면 그거 습득..

