#include<iostream>
using namespace std;

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

bool isSafe(int x, int y, vector<vector<char>>&grid, vector<vector<bool>>&vis){
    int n = grid.size(), m = grid[0].size();
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 'x' && !vis[x][y];
}

bool dfs(int x, int y, vector<vector<char>>&grid, vector<vector<bool>>&vis){
    int n = grid.size(), m = grid[0].size();
    if(x == n - 1) return true;

    vis[x][y] = true;
    for(int k=0;k<8;k++){
        int newx = x + dx[k];
        int newy = y + dy[k];
        if(isSafe(newx, newy, grid, vis)){
            if(dfs(newx, newy, grid, vis)) 
                return true;
        }
    }
    return false;
}

bool isValid(int d, vector<vector<char>>grid, vector<pair<int,int>>&days){
    int n = grid.size(), m = grid[0].size();
    for(int i=0;i<d;i++){
        grid[days[i].first][days[i].second] = 'x';
    }

    vector<vector<bool>>vis(n, vector<bool>(m, false));
    
    // for each col in first row
    for(int i=0;i<m;i++){
        if(grid[0][i] != 'x'){
            if(dfs(0, i, grid, vis) == true)
                return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>>grid(n, vector<char>(m, '.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    int d;
    cin>>d;
    vector<pair<int,int>>days(d);
    for(int i=0;i<d;i++){
        cin>>days[i].first>>days[i].second;
        days[i].first--; 
        days[i].second--;
    }

    int s = 1, e = d, ans = -1;
    while(s <= e){
        int mid = s + (e - s) / 2;
        if(isValid(mid, grid, days)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    if(ans == d)
        ans = -1;
    else if(ans  == -1)
        ans = 1;
    else
        ans++;
    cout<<ans<<endl;
}