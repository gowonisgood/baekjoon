//
// Created by gowon on 2024-09-14.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int freq[26];
int main() {
    string s;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;

    for(auto c : s) freq[c-'a']++;
    for(int i=0;i<26;i++) cout<<freq[i]<<' ';

    return 0;
}
