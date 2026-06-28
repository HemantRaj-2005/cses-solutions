#include <bits/stdc++.h>
#define int long long

const int MOD = 1e9+7;

using namespace std;

vector<int> divs(1e6 + 1, 0);

void sieve() {
    for(int i = 1; i <= 1e6; i++) {
        for(int j = i; j <= 1e6; j += i) {
            divs[j]++;
        }
    }
}

void solve(){
    int x;
    cin >> x;
    cout << divs[x] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    sieve();
    while(n--){
        solve();
    }

    return 0;
}