class Solution {
public:
    int maxCoins(vector<int>& a) {
        a.push_back(1);
        a.insert(a.begin(),1);
        int n=a.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=n-2;i>0;i--){
            for(int j=i;j<=n-2;j++){
                int m=INT_MIN;
                for(int ind=i;ind<=j;ind++){
                    int p=a[ind]*a[i-1]*a[j+1];
                    int q=dp[i][ind-1]+dp[ind+1][j];
                    m=max(m,p+q);
                }
                dp[i][j]=m;
            }
        }
        return dp[1][n-2];
    }
};