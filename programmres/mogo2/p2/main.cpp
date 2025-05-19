#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

//2명 공부 시키기
//같이 공부하면 합이 능력치가 됨
//최소가 되게 해야함

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int a:ability) pq.push(a);

    for(int i=0;i<number;i++){
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();

        int sum = a+b;
        pq.push(sum);
        pq.push(sum);
    }

    while(!pq.empty()){
        answer+=pq.top();
        pq.pop();
    }


    return answer;
}

/* 잘못된 나의 첫번째 풀이 */
/*
#include <iostream>
#include <string>
#include <vector>
//2명 공부 시키기
//같이 공부하면 합이 능력치가 됨
//최소가 되게 해야함

using namespace std;
int visited[1000001];
int solution(vector<int> ability, int number) {
    int answer = 0;
    int min1 = 101;
    int min2 = 101;

    for(int r = 0; r<number; r++){
        for(int vi=0;vi<ability.size();vi++)visited[vi]=0;

        int min1 = 101;
        int min2 = 101;
        int min1_i = 0;
        int min2_i = 0;
        //1. min1 찾기
        for(int i=0;i<ability.size();i++){
            if(ability[i]<=min1) {
                if(!visited[i]){
                    min1 = ability[i];
                    //visited[ability[i]] = 1;
                    min1_i = i;
                }
            }
        }
        visited[min1_i] = 1;

        //2. min 2 찾기
        for(int i=0;i<ability.size();i++){
            if(ability[i]<=min2) {
                if(!visited[i]){
                    min2 = ability[i];
                    //visited[ability[i]] = 1;
                    min2_i = i;
                }

            }
        }
        visited[min2_i] = 1;


        //3. 합 반영하기
        int sum = min1 + min2;
        ability[min1_i]= sum;
        ability[min2_i] = sum;
        //cout << min1 << "\n";
        //cout << min2 << "\n";

        //for(int i=0;i<ability.size();i++) {
        //     cout << ability[i] << " ";
        //}
        //cout << "\n";

    }



    for(int i=0;i<ability.size();i++){
        answer += ability[i];
    }

    return answer;
}
*/