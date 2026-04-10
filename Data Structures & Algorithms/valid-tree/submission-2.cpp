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
    bool validTree(int n, vector<vector<int>>& edges) {
par.assign(n,0);
        iota(par.begin(),par.end(),0);
        rank.assign(n,1);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            int parent_u=parent(u),parent_v=parent(v);
            if(parent_u==parent_v)
            return false;
            if(rank[parent_u]<rank[parent_v])
                par[parent_u]=parent_v;
            else if(rank[parent_u]<rank[parent_v])
                par[parent_v]=parent_u;
            else{
                par[parent_v]=parent_u;
                rank[parent_u]++;
            }
        }
        set<int> s;
        for(int i=0;i<n;i++)
            s.insert(parent(i));
        if(s.size()==1)
        return true;
        return false;
    }
};
