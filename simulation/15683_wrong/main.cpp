#include <iostream>
#include <bits/stdc++.h>

int board[10][10];
int temp[10][10];
int n,m;

void up(int i, int j) {
    for(int ii=i-1;ii>=0;ii--) {
        if(board[ii][j]==6)break;
        if(board[ii][j]!=0)continue;
        board[ii][j] = -5;
    }
}

void down(int i, int j) {
    for(int ii=i+1;ii<n;ii++) {
        if(board[ii][j]==6)break;
        if(board[ii][j]!=0)continue;
        board[ii][j] = -5;
    }
}

void left(int i, int j) {
    for(int jj=j-1;jj>=0;jj--) {
        if(board[i][jj]==6)break;
        if(board[i][jj]!=0)continue;
        board[i][jj] = -5;
    }
}

void right(int i, int j) {
    for(int jj=j+1;jj<m;jj++) {
        if(board[i][jj]==6)break;
        if(board[i][jj]!=0)continue;
        board[i][jj] = -5;
    }
}

int up_v(int i, int j,int bd[][10]) {
    int cnt=0;
    for(int ii=i-1;ii>=0;ii--) {
        if(bd[ii][j]==6)break;
        if(bd[ii][j]!=0)continue;
        bd[ii][j] = -1;
        cnt++;
    }
    //std::cout << i << " " << j << " " << cnt << " up \n" ; //debug
    return cnt;
}

int down_v(int i, int j, int bd[][10]) {
    int cnt=0;
    for(int ii=i+1;ii<n;ii++) {
        if(bd[ii][j]==6)break;
        if(bd[ii][j]!=0)continue;
        bd[ii][j] = -1;
        cnt++;
    }
    //std::cout << i << " " << j << " " << cnt << " down \n" ; //debug
    return cnt;
}

int left_v(int i, int j,int bd[][10]) {
    int cnt = 0;
    for(int jj=j-1;jj>=0;jj--) {
        if(bd[i][jj]==6)break;
        if(bd[i][jj]!=0)continue;
        bd[i][jj] = -1;
        cnt++;
    }

    return cnt;
}

int right_v(int i, int j,int bd[][10]) {
    int cnt = 0;
    for(int jj=j+1;jj<m;jj++) {
        if(bd[i][jj]==6)break;
        if(bd[i][jj]!=0)continue;
        bd[i][jj] = -1;
        cnt++;
    }

    return cnt;
}


using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }

    //case 5
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]==5) {
                //위
                up(i,j);
                //아래
                down(i,j);
                //왼
                left(i,j);
                //오른
                right(i,j);
            }
        }
    }



    //case 4
    int max_4 = 0;
    int case4 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            max_4 = 0;
            if(board[i][j]==4) {
                //임시배열 만들고 더 작으면 업데이트
                int t =  right_v(i,j,temp) + left_v(i,j,temp) + up_v(i,j,temp) ;
                if( t > max_4) {
                    max_4 = t;
                    case4 = 1;
                }
                //temp를 board로 초기화
                memcpy(temp, board, sizeof(board));

                t = right_v(i,j,temp) + down_v(i,j,temp) + up_v(i,j,temp);
                if( t > max_4) {
                    max_4 = t;
                    case4 = 2;
                }
                memcpy(temp, board, sizeof(board));

                t = right_v(i,j,temp) + down_v(i,j,temp) + left_v(i,j,temp);
                if( t > max_4) {
                    max_4 = t;
                    case4 = 3;
                }
                memcpy(temp, board, sizeof(board));

                t =  up_v(i,j,temp) + down_v(i,j,temp) + left_v(i,j,temp);
                if( t > max_4) {
                    max_4 = t;
                    case4 = 4;
                }
                memcpy(temp, board, sizeof(board));

                    switch (case4) {
                        case 1:
                            right(i,j);
                            left(i,j);
                            up(i,j);
                            break;
                        case 2:
                            right(i,j);
                            up(i,j);
                            down(i,j);
                            break;
                        case 3:
                            right(i,j);
                            left(i,j);
                            down(i,j);
                            break;
                        case 4:
                            down(i,j);
                            left(i,j);
                            up(i,j);
                            break;
                        default:
                            break;

                    }
                }
        }
    }

    //case3
    int max_3 = 0;
    int case3 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            max_3 = 0;
            if(board[i][j]==3) {
                //임시배열 만들고 더 작으면 업데이트
                int t =  right_v(i,j,temp) + up_v(i,j,temp);
                if( int t = right_v(i,j,temp) + up_v(i,j,temp) > max_3) {
                    max_3 = t;
                    case3 = 1;
                }
                //temp를 board로 초기화
                memcpy(temp, board, sizeof(board));

                t = right_v(i,j,temp) + down_v(i,j,temp);
                if( t > max_3) {
                    max_3 = t ;
                    case3 = 2;
                }
                memcpy(temp, board, sizeof(board));

                t =  down_v(i,j,temp) + left_v(i,j,temp);
                if( t > max_3) {
                    max_3 = t;
                    case3 = 3;
                }
                memcpy(temp, board, sizeof(board));

                t = up_v(i,j,temp) + left_v(i,j,temp);
                if( t > max_3) {
                    max_3 = t;
                    case3 = 4;
                }
                memcpy(temp, board, sizeof(board));

                    switch (case3) {
                        case 1:
                            right(i,j);
                            up(i,j);
                            break;
                        case 2:
                            right(i,j);
                            down(i,j);
                            break;
                        case 3:
                            left(i,j);
                            down(i,j);
                            break;
                        case 4:
                            left(i,j);
                            up(i,j);
                            break;
                        default:
                            break;

                    }
                }
        }
    }

    //case2
    int max_2 = 0;
    int case2 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            max_2 = 0;
            if(board[i][j]==2) {
                //임시배열 만들고 더 작으면 업데이트
                int t =  up_v(i,j,temp) + down_v(i,j,temp);
                if(  t > max_2) {
                    max_2 = t;
                    case2 = 1;
                }
                //temp를 board로 초기화
                memcpy(temp, board, sizeof(board));

                t = right_v(i,j,temp) + left_v(i,j,temp);
                if( t > max_2) {
                    max_2 = t;
                    case2 = 2;
                }
                memcpy(temp, board, sizeof(board));

                    switch (case2) {
                        case 1:
                            down(i,j);
                            up(i,j);
                        break;
                        case 2:
                            right(i,j);
                            left(i,j);
                            break;
                        default:
                            break;
                    }
                }
        }
    }

    //case1
    int max_1 = 0;
    int case1 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            max_1 = 0;
            if(board[i][j]==1) {
                //임시배열 만들고 더 작으면 업데이트
                int t = up_v(i,j,temp);
                if( t >= max_1) {
                    max_1 = t;
                    case1 = 1;
                }
                //temp를 board로 초기화
                memcpy(temp, board, sizeof(board));

                t = right_v(i,j,temp);
                if( t  >= max_1) {
                    max_1 = t;
                    case1 = 2;
                }
                memcpy(temp, board, sizeof(board));

                t =  down_v(i,j,temp);
                if(t >= max_1) {
                    max_1 = t;
                    case1 = 3;
                }
                memcpy(temp, board, sizeof(board));

                t = left_v(i,j,temp);
                if(t >= max_1) {
                    max_1 = t;
                    case1 = 4;
                }
                memcpy(temp, board, sizeof(board));

                switch (case1) {
                    case 1:
                        up(i,j);
                        break;
                    case 2:
                        right(i,j);
                        break;
                    case 3:
                        down(i,j);
                        break;
                    case 4:
                        left(i,j);
                        break;
                    default:
                        break;
                }
            }
        }
    }



    int cnt = 0;
    /* Debug */
     for(int i=0;i<n;i++) {
         for(int j=0;j<m;j++) {
            cout << board[i][j] << "   ";
        }
        cout << "\n";
    }
    /* Debug */

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j]==0) cnt++;
        }
    }
    cout << cnt;

    return 0;
}
