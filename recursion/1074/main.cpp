#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll func(ll n, ll r, ll c) {
    if(n==0) return 0;
    ll half = (1<<(n-1));
    if(r<half && c <half) return func(n-1, r, c);
    else if(r<half && c >=half) return (half*half)+func(n-1, r, c-half);
    else if(r>=half && c <half) return 2*(half*half)+func(n-1, r-half, c);
    else if(r>=half && c >=half) return 3*(half*half)+func(n-1, r-half, c-half);


}

int main()
{
    ll N,r,c;
    cin >> N >> r >> c;
    cout << func(N,r,c);
    return 0;
}
