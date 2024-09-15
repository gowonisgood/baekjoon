#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin>>N>>K;

    int room[13] = {0,};

    int S=0,Y=0;
    for(int i=0;i<N;i++) {
        cin>>S>>Y;
        if(S==0)  room[Y]+=1;
        else room[Y+6]+=1;
    }

    int cnt = 0;
    for(int i=1;i<13;i++) {
       if(room[i]>0) {
           if(room[i]%K==0) cnt+=(room[i]/K);
           else cnt+=(room[i]/K)+1;
       }
    }

    cout<<cnt;
    return 0;
}
