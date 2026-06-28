#include <bits/stdc++.h>
#define int long long

const int MOD = 1e9+7;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    
    if(n == 1){
        cout << 1 << endl;
        return;
    }

    sort(arr.begin(),arr.end());

    int g = 0;

    for(int i = 1; i < n; i++){
        g = __gcd(g,arr[i]-arr[i-1]);
    }
    if(g == 0) g = 1;

    int mx = arr[n-1];
    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += (mx-arr[i])/g;
    }
    int k = 1;
    int expected = mx - g;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] == expected){
            k++;
            expected -= g;
        }else{
            break;
        }
    }

    ans += k;
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio;
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}