#include <iostream>

using namespace std;

int num[100001];
int cnt[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n;
    int idx=0;

    for(int i=0;i<n;i++) {
        cin>>idx;
        num[i]=idx;
        cnt[idx] = 1;
    }

    cin>>x;
    int sum = 0;

    for(int i=0;i<n;i++) {
        if(cnt[x-num[i]]&&x-num[i]>num[i]&&x-num[i]>=0) {
            sum++;
        }
    }

    cout<<sum;
    return 0;
}
