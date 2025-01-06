#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;

ll power(ll base, ll exp){
    ll res = 1;
    base %= MOD;

    while(exp > 0){
        if(exp%2 == 1) res = (res*base)%MOD;
        base = (base*base)%MOD;
        exp/=2;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << power(2,n)<< endl;
    return 0;
}