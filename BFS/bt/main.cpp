#include <iostream>
#include <vector>

using namespace std;


void dfs(int start, int n, int k, vector<int> &path) {
    if(path.size()==k) {
        for(int num : path) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }else {
        for(int i=start;i<=n;i++) {
            path.push_back(i);
            dfs(i+1,n,k,path);
            path.pop_back();
        }
    }
}



int main() {
    int n=4;
    vector<int> path;

    for(int i=0;i<n;i++) {
        cout<<"size :"<<i<<"\n";
        dfs(0,n,i,path);
        //cout<<"\n"
    }
    return 0;
}




// void dfs(int start, int n, int k, vector<int>& path){
//     if(path.size()==k){
//         for(int num:path) {
//             cout << num << " ";
//         }
//         cout << "\n";
//         return;
//     }
//
//     for(int i = start; i <=n; i++) {
//         path.push_back(i);
//         dfs(i+1, n, k, path);
//         path.pop_back();
//     }
// }
//
// int main()
// {
//     int n= 4;
//     vector<int> path;
//
//     for(int k=1;k<=n;k++) {
//         cout<<"size"<<k<< ": \n";
//         dfs(1,n,k,path);
//         cout << "\n";
//     }
//
//     return 0;
// }
