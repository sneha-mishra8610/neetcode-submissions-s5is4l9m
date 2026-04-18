class Solution {
public:
int m,n;
bool check(int x,int y){
    if(x>=0&&x<m&&y>=0&&y<n)
    return true;
    return false;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    queue<vector<int>> q;
                    q.push({i,j});
                    vis[i][j]=1;
                    int size=1;
                    while(!q.empty()){
                        int x=q.front()[0],y=q.front()[1];
                        q.pop();
                        for(int i=0;i<4;i++){
                            int x_next=x+dir[i].first,y_next=y+dir[i].second;
                            if(check(x_next,y_next)&&!vis[x_next][y_next]&&grid[x_next][y_next]==1){
                                q.push({x_next,y_next});
                                vis[x_next][y_next]=1;
                                size++;
                            }
                        }
                    }
                    ans=max(ans,size);
                }
            }
        }
        return ans;
    }
};