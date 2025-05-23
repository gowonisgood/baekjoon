#include <iostream>
#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
int n,m; //노트북의 가로, 세로
int k; //스티커의 개수

//int sticker[12][12];


int board1[42][42];
int board2[42][42];

int visited1[42][42];
int visited2[42][42];

bool OOB(int x,int y) {
    if(x<0||y<0||x>=n||y>=m) return true;
    return false;
}

//TODO:rotation 함수 만들기


int main() {
    cin >> n >> m;
    cin >> k;

    for(int sti=0;sti<k;sti++) {
        //1. input
        //1-1. 스티커 크기 입력
        int r,c;
        cin >> r >> c;
        //1-2. 스티커 값 입력 (좌표를 vector에 담음)
        int tmp;
        queue<pair<int,int>> sticker; //TODO:이렇게하면 매 배열마다 초기화 되는거 맞는지 확인
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin >> tmp;
                if(tmp==1)sticker.push({i,j});
            }
        }
        //1.스티커를 붙일 수 있는 위치를 찾는다 (붙일 수 있는 한 가장 왼쪽 위)
        //2. 붙일 수 없으면 90도 회전후 ^ 위 과정 반복 (4번)

        //0.bfs로 풀 수 있을 거 같음
        //1.스티커를 붙인칸은 1로 표기후

        //2. 노트북에 붙일 수 있는가?
        bool find_flag = false;
        for(int rota=0;rota<4;rota++) {

            if(find_flag) break;

            for(int i=0;i<n;i++) {

                if(find_flag) break;
                for(int j=0;j<m;j++) {

                    bool isNotStick = false;
                    while(!sticker.empty()) {
                        pair<int,int> cur = sticker.front();
                        sticker.pop();

                        int nx = i + cur.X;
                        int ny = j + cur.Y;

                        board2[nx][ny] = 1;

                        if(OOB(nx,ny)||board1[nx][ny]==1) {
                            isNotStick=true;
                            memcpy(board2,board1,sizeof(board2));
                            break;
                        }
                    }
                    if(!isNotStick) {
                        find_flag = true;
                        memcpy(board1,board2,sizeof(board2));
                    }

                }
            }


        }

        /* Debug */
         for(int i=0;i<n;i++) {
             for(int j=0;j<m;j++) {
                 cout << board2[i][j] << "  ";
             }
             cout << "\n";
         }


        //3.각 배열 초기화
        // //3-1 스티커 배열 초기화
        // for(int i=0;i<r;i++) {
        //     for(int j=0;j<c;j++) {
        //         sticker[i][j]=0;
        //     }
        // }




    }



    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
