#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>s;
    int arr[26];
    fill(arr,arr+26,0);

    for(int i=0;i<s.size();i++){
        arr[s[i]-'a'] ++;
    }

    for(int i=0;i<26;i++) {
        cout<<arr[i]<<' ';
    }

    return 0;
}
