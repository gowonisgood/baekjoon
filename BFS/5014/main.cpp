#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int building[1000003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    fill(building, building + 1000003, -1);

    queue<int> Q;
    building[S] = 0;
    Q.push(S);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int nxt : {cur + U, cur - D}) {
            if (nxt < 1 || nxt > F) continue;
            if (building[nxt] != -1) continue;
            building[nxt] = building[cur] + 1;
            Q.push(nxt);
        }
    }

    if (building[G] == -1)
        cout << "use the stairs";
    else
        cout << building[G];

    return 0;
}
