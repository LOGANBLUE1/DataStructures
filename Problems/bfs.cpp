#include<iostream>
using namespace std;


inline bool valid(int x,int y,int r,int c) { return x>=0 && x<r && y>=0 && y<c;}
void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis, int x, int y, int r, int c){
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y] = true;
    while(!q.empty()){
        auto f = q.front(); q.pop();
        int fx = f.first, fy = f.second;
        for(int i=0;i<4;i++){
            int nx = fx+dx[i], ny = fy+dy[i];
            if(valid(nx,ny,r,c) && grid[nx][ny] == '1' && !vis[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny] = true;
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    vector<vector<bool>> vis(m, vector<bool>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '1' && !vis[i][j]){
                bfs(grid,vis,i,j,m,n);
                count++;
            }
        }
    }
    return count;
}

int main(){
    
    return 0;
}