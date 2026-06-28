#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

template<typename T>
void print_1dvector(vector<T>& v) {
    for(size_t i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void take_1d_vector_input(vector<T> &v){
    for(auto &i : v){
        cin >> i;
    }
}

template<typename T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }


bool dfs(int node, vector<vector<int>> &adj, vector<int> &team){
    for(int it : adj[node]){
        if(team[it] == 0){
            team[it] = 3 - team[node];
            if(!dfs(it, adj, team)) return false;
        }
        else if(team[it] == team[node]){
            return false;
        }
    }
    return true;
}




signed main(){
    fast_io;
    int n,m;
    cin >> n >> m;
    vector<int> team(n+1,0);
    vector<vector<int>> adj(n+1);


    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    for(int i = 1; i <= n; i++){
        if(team[i] == 0){
            team[i] = 1;
            if(!dfs(i, adj, team)){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    print_1dvector(team);


    return 0;

}