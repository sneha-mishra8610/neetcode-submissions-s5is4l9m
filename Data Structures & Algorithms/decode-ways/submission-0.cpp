class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int c=s[i-1]-'0';
            if(i==1){
                if(c==0)
                dp[i]=0;
                else
                dp[i]=1;
                continue;
            }
            int d=s[i-2]-'0';
            if(c==0){
                if(d>2||d==0)
                dp[i]=0;
                else
                dp[i]=dp[i-2];
            }else{
                dp[i]=dp[i-1];
                if(d==1)
                dp[i]+=dp[i-2];
                else if((d==2)&&(c<7))
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};