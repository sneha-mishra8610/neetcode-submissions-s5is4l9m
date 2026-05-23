#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            graph[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dis(n,1e9);
        while(!q.empty()){
            int stop=q.front().f;
            int node=q.front().s.f;
            int cost=q.front().s.s;
            q.pop();
            if(stop>=k)
            continue;
            for(auto branch:graph[node]){
                int v=branch.f;
                int w=branch.s;
                if(cost+w<dis[v]&&stop+1<=k){
                    dis[v]=cost+w;
                    q.push({stop+1,{v,dis[v]}});
                }
            }
        }
        if(dis[dst]==1e9)
        return -1;
        return dis[dst];
    }
};