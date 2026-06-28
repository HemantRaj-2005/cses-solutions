#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

template<typename T>
void print_1dvector(vector<T>& v) {
    for(size_t i = 0; i < v.size(); i++) {
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

void dfs(ll node, ll &lastNode,vector<vector<ll>> &adj, vector<bool> &visited){
    visited[node] = 1;
    lastNode = node;

    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, lastNode,adj, visited);
        }
    }
}

signed main(){
    fast_io;
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> edges(m);
    vector<bool> visited(n+1,0);
    vector<vector<ll>> adj(n+1);
    for(ll i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        edges.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll roads = -1;
    vector<pair<ll,ll>> roadPair;
    ll lastNode = -1;
    for(ll i = 1; i <= n; i++){
        if(!visited[i]){
            if(lastNode != -1){
                roadPair.push_back({lastNode,i});
            }
            dfs(i,lastNode,adj,visited);
            roads++;
        }
    }

    cout << roads << endl;
    for(auto it : roadPair){
        cout << it.first << " " << it.second << endl;
    }


    return 0;
    
}