class Solution {
    int r;
    int c;
    int vx[5] = {0,1,0,-1,0};
public:
    int markAndCountHit(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]!=1){
            return 0;
        }
        grid[i][j] = 2;
        int count = 1;

        for(int k=0;k<4;k++)
            count += markAndCountHit(grid, i+vx[k], j+vx[k+1]);
        return count;
    }

    bool isConnectedToTop(vector<vector<int>>& grid, int x, int y){
        return (x>0 && grid[x-1][y]==2) || (y<c-1 && grid[x][y+1]==2) ||
            (y>0 && grid[x][y-1]==2) || (x<r-1 && grid[x+1][y]==2) || x==0;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        this->r = grid.size(), this->c = grid[0].size();
        for(auto it: hits){
            if(grid[it[0]][it[1]])
                grid[it[0]][it[1]] = 0;
            else
                grid[it[0]][it[1]] = -1;// if it is 0 -> no changes will happen
        }
        for(int j=0;j<c;++j){
            if(grid[0][j])
                markAndCountHit(grid,0,j);
        }

        int q = hits.size();
        vector<int> ans(q,0);
        for(int i=q-1;i>=0;--i){
            int x = hits[i][0], y = hits[i][1];
            if(grid[x][y]!=-1){//  -1 => it was already zero, so no changes
                grid[x][y] = 1;
                if(isConnectedToTop(grid, x, y))
                    ans[i] = markAndCountHit(grid,x,y)-1;
            }
            
        }
        return ans;
    }
};//on each col on row zero bricks are sticked and all the bricks connected to them
//are the bricks that will be stable, on every hit we remove a brick count the no. of bricks that will go with it