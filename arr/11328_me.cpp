#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    string a,b;
    int first[26];
    int second[26];

    for(int i=0;i<N;i++) {
        cin>>a>>b;
        fill_n(first,26,0);
        fill_n(second,26,0);
        //[1].marking
        for(int j=0;j<a.size();j++) {
            first[a[j]-'a']++;
            second[b[j]-'a']++;
        }
        //[2].check
        int flag = 1;
        for(int j=0;j<26;j++) {
            if(first[j]!=second[j]) {
                cout<<"Impossible\n";
                flag = 0;
                break;
            }
        }
        if(flag) cout<<"Possible\n";
    }
    return 0;
}
