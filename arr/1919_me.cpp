#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//*** WARNING *** to be careful of bound checking , size of word can be different
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    int first[26];
    int second[26];


    cin>>a>>b;
    fill_n(first,26,0);
    fill_n(second,26,0);
    //[1].marking
    for(int j=0;j<a.size();j++) {
        first[a[j]-'a']++;
    }
    for(int j=0;j<b.size();j++) {
        second[b[j]-'a']++;
    }
    //[2].check
    int cnt=0;
    for(int j=0;j<26;j++) {
        if(first[j]!=second[j]) {
            cnt+=abs(first[j]-second[j]);
        }
    }

    cout<<cnt;

    return 0;
}
