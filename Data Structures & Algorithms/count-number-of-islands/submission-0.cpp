class Solution {
public:
    int ans=0,m,n;
    vector<vector<int>> vis;
    vector<vector<char>> grid;
    void dfs(int r,int c){
        int x=r-1,y=c;
        if(x>=0&&grid[x][y]=='1'&&!vis[x][y]){
        vis[x][y]=1;
        dfs(x,y);
        }
        x=r+1;
        if(x<m&&grid[x][y]=='1'&&!vis[x][y]){
        vis[x][y]=1;
        dfs(x,y);
        }
        x=r,y=c-1;
        if(y>=0&&grid[x][y]=='1'&&!vis[x][y]){
        vis[x][y]=1;
        dfs(x,y);
        }
        y=c+1;
        if(y<n&&grid[x][y]=='1'&&!vis[x][y]){
        vis[x][y]=1;
        dfs(x,y);
        }
    }
    int numIslands(vector<vector<char>>& g) {
        m=g.size();
        n=g[0].size();
        vis.resize(m);
        grid=g;
        for(int i=0;i<m;i++)
        vis[i].resize(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                vis[i][j]=1;
                dfs(i,j);
                ans++;
                }
            }
        }
        return ans;
    }
};