class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<vector<int>> dp1(2,vector<int> (n,0));
        vector<vector<int>> dp2(2,vector<int> (n+1,0));
        for(int i=0;i<n-1;i++){
            dp1[0][i+1]=nums[i]+dp1[1][i];
            dp1[1][i+1]=max(dp1[0][i],dp1[1][i]);
        }
        int m=max(dp1[0][n-1],dp1[1][n-1]);
        for(int i=1;i<n;i++){
            dp2[0][i+1]=nums[i]+dp2[1][i];
            dp2[1][i+1]=max(dp2[0][i],dp2[1][i]);
        }
        m=max(m,max(dp2[0][n],dp2[1][n]));
        return m;
    }
};