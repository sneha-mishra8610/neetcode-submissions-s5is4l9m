#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int i,int j,int n,int m) {
    if((i<0)||(i>=n)||(j<0)||(j>=m))
        return false;
    else
        return true;
    }
    int orangesRotting(vector<vector<int>>& arr) {
    int n,m;
    n=arr.size();
    m=arr[0].size();
    int dp[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) 
            dp[i][j]=-1;
    }
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]==2) {
                dp[i][j]=0;
                q.push(make_pair(i,j));
            }
        }
    }
    int k=0,s=0;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        int i=p.first;
        int j=p.second;
        if(check(i-1,j,n,m)&&(dp[i-1][j]==-1)&&arr[i-1][j]==1) {
            dp[i-1][j]=dp[i][j]+1;
            q.push(make_pair(i-1,j));
        }
        if(check(i+1,j,n,m)&&(dp[i+1][j]==-1)&&arr[i+1][j]==1) {
            dp[i+1][j]=dp[i][j]+1;
            q.push(make_pair(i+1,j));
        }
        if(check(i,j-1,n,m)&&(dp[i][j-1]==-1)&&arr[i][j-1]==1) {
            dp[i][j-1]=dp[i][j]+1;
            q.push(make_pair(i,j-1));
        }
        if(check(i,j+1,n,m)&&(dp[i][j+1]==-1)&&arr[i][j+1]==1) {
            dp[i][j+1]=dp[i][j]+1;
            q.push(make_pair(i,j+1));
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1&&dp[i][j]==-1)
            k++;
            s=max(s,dp[i][j]);
        }
    }
    if(k==0)
        return s;
    else
        return -1;
    }
};