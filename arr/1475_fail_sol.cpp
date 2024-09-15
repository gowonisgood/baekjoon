#include <iostream>
#include <string>

using namespace std;
int numset[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string N;
    cin>>N;

    int Nint=0;
    for(int i=0;i<N.size();i++){
        Nint = N[i]-'0';
        if(Nint==9) numset[6]++;
        else numset[Nint] ++;
    }
     numset[6] = (numset[6]+1)/2;

    //[2].for times add all
    int cnt=0;
    for(int i=0;i<9;i++) cnt=max(cnt,numset[i]);
    cout<<cnt;
    return 0;
}
