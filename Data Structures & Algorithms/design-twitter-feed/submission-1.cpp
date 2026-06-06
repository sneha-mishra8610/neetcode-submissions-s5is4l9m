#include <bits/stdc++.h>
class Twitter {
public:
int time=0;
int graph[501][501];
vector<priority_queue<pair<int,int>>> pq;
    Twitter() {
        memset(graph,0,sizeof(graph));
        pq.resize(501);
    }
    
    void postTweet(int userId, int tweetId) {
        pq[userId].push({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> p;
        vector<pair<int,int>> ans;
        for(int i=0;i<501;i++){
            if(graph[userId][i]>0||userId==i){
                priority_queue<pair<int,int>> q=pq[i];
                int k=10;
                while(!q.empty()&&k>0){
                    ans.push_back(q.top());
                    q.pop();
                }
            }
        }
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        vector<int> res;
        for(int i=0;i<min((int)ans.size(),10);i++)
        res.push_back(ans[i].second);
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(graph[followerId][followeeId]==0)
        graph[followerId][followeeId]++;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(graph[followerId][followeeId]>0)
        graph[followerId][followeeId]--;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */