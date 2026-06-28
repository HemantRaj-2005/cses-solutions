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


void dfs(int row,int col, int n, int m,vector<vector<char>> &grid, vector<vector<bool>> &visited){
    visited[row][col] = 1;

    int dr[] = {-1,0,1,0};
    int dc[] = {0,-1,0,1};

    for(int i = 0; i < 4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.' && !visited[nr][nc]){
            dfs(nr,nc,n,m,grid,visited);
        }
    }
    
}

signed main(){
    fast_io;
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<bool>> visited(n,vector<bool>(m,0));


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                dfs(i,j,n,m,grid,visited);
                ans++;
            }
        }
    }

    cout << ans << endl;

}