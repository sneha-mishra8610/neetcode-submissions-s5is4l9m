class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length(),l=s3.length();
        int len=max(n,m);
        if(n+m!=l)
        return false;
        vector<vector<bool>> dp(len+1,vector<bool> (len+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                bool a=false,b=false;
                if(i+j<1)
                continue;
                if(i>=1&&s1[i-1]==s3[i+j-1])
                a=dp[i-1][j];
                if(j>=1&&s2[j-1]==s3[i+j-1])
                b=dp[i][j-1];
                dp[i][j]=a|b;
            }
        }
        return dp[n][m];
    }
};