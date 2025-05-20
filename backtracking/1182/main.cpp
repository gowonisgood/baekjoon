#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int S;
int cnt;
int board[30];

void func(int cur, int tot) {
    if(cur == N) {
        if(tot == S) cnt++;
        return;
    }
    func(cur+1, tot);
    func(cur+1, tot+board[cur]);
}

int main() {
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> board[i];
    func(0,0);

    if(S == 0) cnt --;
    /* S가 0인 경우, func에서 공집합이 포함 됨 */
    cout << cnt;
}

// #include <iostream>
// #include <bits/stdc++.h>
//
// using namespace std;
// int N;
// int S;
//
// int board[22];
// int visited[22];
//
// int cnt;
//
// void func(int k) {
//     if(k==S) {
//         cnt++;
//         return;
//     }
//     for(int i=0;i<N;i++) {
//         if(visited[i]) continue;
//         visited[i] = 1;
//         func(k+board[i]);
//         visited[i] = 0;
//     }
// }
//
// /* 이 풀이의 문제점 : 가능한 모든 수열을 고려하지 않음 */
//
//
// int main()
// {
//     cin >> N >> S;
//     for(int i=0;i<N;i++) cin >> board[i];
//     func(0);
//     cout << cnt;
//
//
//     //std::cout << "Hello, World!" << std::endl;
//     return 0;
// }
