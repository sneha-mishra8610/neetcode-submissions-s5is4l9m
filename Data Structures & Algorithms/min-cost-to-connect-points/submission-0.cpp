#define f first
#define s second
#define ll long long
class Solution {
public:
vector<int> par;
vector<int> rank;
int find_par(int node){
    if(par[node]==node)
    return node;
    else{
        int p=find_par(par[node]);
        par[node]=p;
        return p;
    }
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                edges.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
        }
        sort(edges.begin(),edges.end());
        for(int i=0;i<n;i++){
        par.push_back(i);
        rank.push_back(1);
        }
        int cost=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][1],v=edges[i][2];
            int p1=find_par(u),p2=find_par(v);
            if(p1==p2)
            continue;
            else{
                cost+=edges[i][0];
                int r1=rank[p1],r2=rank[p2];
                if(r1<r2){
                    par[p1]=p2;
                }else if(r2<r1){
                    par[p2]=p1;
                }
                else{
                    par[p1]=p2;
                    rank[p2]++;
                }
            }
        }
        return cost;
    }
};