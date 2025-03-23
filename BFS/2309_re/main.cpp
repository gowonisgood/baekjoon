#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(9);
vector<int> backtracking(int start, int n, vector<int>& arr, vector<int>& visited) {
    if(visited.size()==7) {
        int sum = 0;
        for(int i=0;i<7;i++) {
            sum += visited[i];
        }
        if(sum==100) return visited;
        return {};
    }else {
        for(int i=start; i<9; i++) {
            visited.push_back(arr[i]);
            vector<int> sol = backtracking(i+1, n,arr,visited);
            if(!sol.empty()) return sol;
            visited.pop_back();
        }
    }
    return {};
}


int main()
{
    vector<int> visited;
    for(int i=0;i<9;i++) {
        cin >> arr[i];
    }

    vector<int> sol = backtracking(0,7,arr,visited);

    std::sort(sol.begin(), sol.end());

    for(int i=0;i<7;i++) {
        cout << sol[i] <<"\n";
    }
    return 0;
}
