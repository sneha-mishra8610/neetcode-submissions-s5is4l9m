class Solution {
public:
vector<vector<int>> graph;
vector<bool> visited;
void dfs(int node){
    if(visited[node])
    return;
    visited[node]=true;
    for(auto u:graph[node])
    dfs(u);
    return;
}
    int countComponents(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        visited.assign(n,false);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
            dfs(i);
            components++;
            }
        }
        return components;
    }
};
