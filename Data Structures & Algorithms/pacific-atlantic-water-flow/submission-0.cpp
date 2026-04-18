class Solution {
public:
int m,n;
bool check(int x,int y){
    if(x>0&&x<=m&&y>0&&y<=n)
    return true;
    return false;
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();n=heights[0].size();
        vector<pair<int,int>> v={{0,1},{1,0},{-1,0},{0,-1}};
        queue<vector<int>> q;
        for(int i=0;i<=n+1;i++)
        q.push({0,i,0});
        for(int i=1;i<=m;i++)
        q.push({i,0,0});
        vector<vector<int>> vis_pac(m+2,vector<int>(n+1,0));
        while(!q.empty()){
            int x=q.front()[0],y=q.front()[1],height=q.front()[2];
            q.pop();
            for(int i=0;i<4;i++){
                int x_next=x+v[i].first,y_next=y+v[i].second;
                if(check(x_next,y_next)&&heights[x_next-1][y_next-1]>=height&&!vis_pac[x_next][y_next]){
                    q.push({x_next,y_next,heights[x_next-1][y_next-1]});
                    vis_pac[x_next][y_next]++;
                }
            }
        }
        for(int i=0;i<=n+1;i++)
        q.push({m+1,i,0});
        for(int i=1;i<=m;i++)
        q.push({i,n+1,0});
        vector<vector<int>> vis_atl(m+2,vector<int>(n+1,0));
        while(!q.empty()){
            int x=q.front()[0],y=q.front()[1],height=q.front()[2];
            q.pop();
            for(int i=0;i<4;i++){
                int x_next=x+v[i].first,y_next=y+v[i].second;
                if(check(x_next,y_next)&&heights[x_next-1][y_next-1]>=height&&!vis_atl[x_next][y_next]){
                    q.push({x_next,y_next,heights[x_next-1][y_next-1]});
                    vis_atl[x_next][y_next]++;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(vis_pac[i][j]&&vis_atl[i][j])
                ans.push_back({i-1,j-1});
            }
        }
        return ans;
    }
};