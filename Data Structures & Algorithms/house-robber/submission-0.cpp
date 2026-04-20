class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(2,vector<int> (n+1,0));
        for(int i=0;i<n;i++){
            dp[0][i+1]=nums[i]+dp[1][i];
            dp[1][i+1]=max(dp[0][i],dp[1][i]);
        }
        return(max(dp[0][n],dp[1][n]));
    }
};