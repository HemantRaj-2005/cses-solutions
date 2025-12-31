
#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)(v).size())
#define F first
#define S second

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// *using next_permutation STL of cpp
/*
void solve(string s) {
    sort(all(s));
    vector<string> ans;
    do {
        ans.pb(s);
    } while(next_permutation(all(s)));
    cout << sz(ans) << "\n";
    for(auto x : ans) cout << x << "\n";

}

*/

bool get_next_permutation(string &s)
{
    int n = sz(s);
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    if (i < 0)
        return false;
    int j = n - 1;
    while (s[j] <= s[i])
        j--;
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    return true;
}

int main()
{
    fast_io;
    string s;
    cin >> s;
    sort(all(s));
    vector<string> ans;
    ans.pb(s);
    while (get_next_permutation(s))
    {
        ans.pb(s);
    }
    sort(all(ans));

    cout << sz(ans) << "\n";
    for (auto x : ans)
        cout << x << "\n";
    
    return 0;
}
