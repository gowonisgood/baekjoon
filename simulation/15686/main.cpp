#include <iostream>
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N,M; //M은 치킨집을 최대 M개 골랐을때 최솟값
int chi_min = INT32_MAX; // 치킨 거리 최솟값

//0은 빈칸, 1은 집, 2는 치킨집
//r과 c는 1부터 시작
//output : 치킨 거리의 최솟값
//*집도 여러개일 수 있음


vector<pair<int,int>> chicken;
int select_chicken[102];

vector<pair<int,int>> home;
// vector<int> min_d_home(3000,INT32_MAX);


void distance() {
    int d = 0;
    vector<int> min_d_home(3000,INT32_MAX);

    for(int chi=0;chi<chicken.size();chi++) {

        if(select_chicken[chi]==1) {
            //cout << "c: " << c << " chicken: " << chicken[c].X <<", " << chicken[c].Y<<" "; //debug

            for(int i=0;i<home.size();i++) {
                pair<int,int> cur_home = home[i];

                int homeX = cur_home.X;
                int homeY = cur_home.Y;

                int r = chicken[chi].X - homeX;
                int c = chicken[chi].Y - homeY;

                if(r<0) r = -r;
                if(c<0) c = -c;

                d = r+c;

                if(min_d_home[i]>d) {min_d_home[i] =d;}
            }
        }
    }


    int sum = 0;
    for(int i=0;i<home.size();i++) sum+=min_d_home[i];
    chi_min = min(chi_min,sum);

}

void select(int start, int n) {

    if(n==M) {
        distance();
        return;
    }

    for(int i=start;i<chicken.size();i++) {
        if(select_chicken[i]==1) continue;
        select_chicken[i] = 1;
        select(i+1,n+1);
        select_chicken[i] = 0;
    }

}


int main() {
    cin >> N >> M;
    int tmp;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> tmp;
            if(tmp==1) home.push_back({i,j});
            if(tmp==2) chicken.push_back({i,j});
        }
    }

    select(0,0);

    //1. 폐업 안시킬 치킨 집 선택 ㅇㅋ
    //2. 남은 치킨집 과 집의 거리


    cout << chi_min;
    return 0;
}
