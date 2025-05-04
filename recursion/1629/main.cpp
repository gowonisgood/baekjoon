#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a,b,c;
ll nmj;


int mul(ll a, ll b, ll c) {
    if(b==1) return a%c;

    ll val = mul(a,b/2,c);

    val = val*val%c;
    if(b%2==0) return val;
    return val*a%c;

}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    int result = mul(a,b,c);
    cout << result;
    return 0;
}
