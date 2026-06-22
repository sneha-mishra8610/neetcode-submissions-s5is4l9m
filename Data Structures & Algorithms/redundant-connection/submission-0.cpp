class Solution {
public:
vector<int> par;
vector<int> rank;
int parent(int node){
    if(par[node]==node)
    return node;
    par[node]=parent(par[node]);
    return par[node];
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.assign(n,0);
        iota(par.begin(),par.end(),0);
        rank.assign(n,1);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            u--;v--;
            int parent_u=parent(u),parent_v=parent(v);
            if(parent_u==parent_v)
            return edge;
            if(rank[parent_u]<rank[parent_v])
                par[parent_u]=parent_v;
            else if(rank[parent_u]<rank[parent_v])
                par[parent_v]=parent_u;
            else{
                par[parent_v]=parent_u;
                rank[parent_u]++;
            }
        }
        return {0,0};
    }
};