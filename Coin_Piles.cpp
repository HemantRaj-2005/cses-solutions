#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll TC;
    cin >> TC;

    while (TC--)
    {
        ll a, b;
        cin >> a >> b;
        if(a > b) swap(a,b);

        if(b > 2*a || (a+b)%3 != 0){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
