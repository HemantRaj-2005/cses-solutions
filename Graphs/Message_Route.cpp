#include <bits/stdc++.h>
#define int long long
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




signed main(){
    fast_io;
    int n,m;
    cin >> n >> m;
    vector<bool> visited(n+1);
    vector<int> parent(n+1,-1);
    vector<vector<int>> adj(n+1);


    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    visited[1] = 1;
    parent[1] = 1;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){

            if(!visited[it] ){
                visited[it] = 1;
                parent[it] = node;
                q.push(it);
            }
        }

    }
    int node = n;
    if(!visited[n]){
        cout << "IMPOSSIBLE" << endl;
    } else{
        vector<int> ans;
        while(n >= 1){
            ans.push_back(n);
            n = parent[n];
            if(parent[n] == 1 && n == 1){
                break;
            }
        }
        ans.push_back(1);
        reverse(all(ans));
        cout << ans.size() << endl;
        print_1dvector(ans);
    }

    return 0;

}