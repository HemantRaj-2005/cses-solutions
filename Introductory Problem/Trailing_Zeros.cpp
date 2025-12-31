#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll zero = 0;

    for(ll i  = 5; n/i >= 1; i*=5){
        zero += n/i;
    }

    cout << zero << endl;


    return 0;
}