
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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

void tower_of_hanoi(int n, int from, int to, int aux) {
    if(n==1){
        cout << from << " " << to << "\n";
        return;
    }
    tower_of_hanoi(n-1, from, aux, to);
    cout << from << " " << to << "\n";
    tower_of_hanoi(n-1, aux, to, from);
}

int main() {
    fast_io;
    ll n;
    cin >> n;
    cout << pow(2,n) - 1 << "\n";
    tower_of_hanoi(n, 1, 3, 2);
}
