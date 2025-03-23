#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, int n, int k, vector<int>& path){
    if(path.size()==k){
        for(int num:path) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = start; i <=n; i++) {
        path.push_back(i);
        dfs(i+1, n, k, path);
        path.pop_back();
    }
}

int main()
{
    int n= 4;
    vector<int> path;

    for(int k=1;k<=n;k++) {
        cout<<"조합 크기"<<k<< ": \n";
        cout << "\n";
    }

    return 0;
}
