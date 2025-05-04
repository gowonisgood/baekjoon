#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void func(int a, int b, int n) {

    if(n==1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a,6-a-b,n-1); //작은 원판 a -> 보조 기둥
    cout << a << ' '<< b << '\n'; // 큰 원판 a->b로 이동
    func(6-a-b, b, n-1); // 작은 원판 보조 -> b로 이동
}


int main()
{

    int k;
    cin >> k;
    cout << (1<<k)-1<<'\n';
    func(1,3,k);
    return 0;
}
