class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
        return(0);
        int n=coins.size();
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        dp[i]=-1;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i==coins[j])
                    dp[i]=1;
                else if((i>coins[j])&&(dp[i-coins[j]]>0)){
                    if(dp[i]==-1)
                    dp[i]=dp[i-coins[j]]+1;
                    else
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return(dp[amount]);
    }
};