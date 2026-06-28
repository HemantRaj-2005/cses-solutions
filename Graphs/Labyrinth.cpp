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
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,pair<int,int>(INT_MAX,INT_MAX)));
    vector<vector<char>> moves(n,vector<char>(m));

    int sr,sc,er,ec;
    int dr[] = {-1,0,1,0};
    int dc[] = {0,-1,0,1};
    char direction[] = {'U','L','D','R'};


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                sr = i;
                sc = j;
            }
            if(grid[i][j] == 'B'){
                er = i;
                ec = j;
            }
        }
    }

    queue<pair<int,int>> q;
    visited[sr][sc] = 1;
    parent[sr][sc] = {-1,-1};
    q.push({sr,sc});

    while(!q.empty()){
        auto it = q.front();
        int row = it.first;
        int col = it.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = row+dr[i];
            int nc = col+dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && !visited[nr][nc] ){
                visited[nr][nc] = 1;
                parent[nr][nc] = {row,col};
                moves[nr][nc] = direction[i];
                q.push({nr,nc});
            }
        }

    }
    string path;

    if(!visited[er][ec]){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
        int r = er,c=ec;
        while(parent[r][c].first != -1 && parent[r][c].second != -1){
            path.push_back(moves[r][c]);
            auto p = parent[r][c];
            r = p.first;
            c = p.second;
        }
        reverse(all(path));
        cout << path.size() << endl;
        cout << path << endl;
    }

    return 0;

}