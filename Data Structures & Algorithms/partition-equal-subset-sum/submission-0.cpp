#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool canPartition(vector<int>& v) {
        int n=v.size();
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=v[i];
        if(sum%2==1)
        return(false);
        int target=sum/2;
        int dp[n+1][target+1];
        for(int i=0;i<=target;i++)
        dp[0][i]=0;
        for(int i=0;i<=n;i++)
        dp[i][0]=1;
        for(int i=1;i<=target;i++){
            for(int j=1;j<=n;j++){
                dp[j][i]=dp[j-1][i];
                if(i>=v[j-1]){
                    if(dp[j-1][i-v[j-1]]!=0)
                    dp[j][i]=1;
                }
            }
        }
        if(dp[n][target]==1)
        return(true);
        else
        return(false);
    }
};