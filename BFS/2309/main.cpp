#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(9);
vector<bool> visited(9, false);

vector<int> find_combination(int start, int r) {
    if (r == 0) {
        vector<int> sol;
        int sum = 0;

        for (int i = 0; i < 9; i++) {
            if (visited[i]) {
                sum += arr[i];
                sol.push_back(arr[i]);
            }
        }

        if (sum == 100) return sol;
        return {};
    }

    for (int i = start; i < 9; i++) {
        visited[i] = true;
        vector<int> result = find_combination(i + 1, r - 1);
        if (!result.empty()) return result;
        visited[i] = false;
    }

    return {};
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    vector<int> result = find_combination(0, 7);

    if (!result.empty()) {
        sort(result.begin(), result.end());
        for (int num : result) {
            cout << num << '\n';
        }
    }

    return 0;
}

/* MY SOLUTION*/
// #include <iostream>
// using namespace std;
//
// int arr[9];
// bool visited[9];
//
// int sol[9];
//
//
// int* comb1(int* arr,bool* visited, int start, int r) {
//     if(r==0) {
//         int sum = 0;
//         for(int i=0; i<7; i++) sol[i] = 0;
//
//         for(int i=0; i<9; i++) {
//             if(visited[i] == true) {
//                 sum += arr[i];
//                 sol[i] = arr[i];
//             }else {
//                 //printf("debug: %d\n",i);
//                 sol[i] = 0;
//             }
//         }
//         if(sum==100) return sol; /*TODO*/
//         return nullptr;
//     }
//     else {
//         for(int i=start; i<9; i++) {
//             visited[i] = true;
//             int *result = comb1(arr, visited, i+1, r-1); //중요 - 여기서 반환값을 반드시 체크해줘야함
//             if(result) return result;
//             visited[i] = false;
//         }
//     }
//
//     return nullptr;
// }
//
// int main()
// {
//
//     for(int i = 0; i < 9; i++) {
//         cin >> arr[i];
//     }
//
//     int *r = comb1(arr, visited, 0, 7);
//
//     for(int i=0;i<9;i++) {
//         for(int j=i;j<9;j++) {
//             if(r[i]>r[j]) {
//                 int temp = r[i];
//                 r[i] = r[j];
//                 r[j] = temp;
//             }
//         }
//     }
//
//     for(int i=2; i<9; i++) {
//         printf("%d\n", r[i]);
//     }
//
//     return 0;
// }
