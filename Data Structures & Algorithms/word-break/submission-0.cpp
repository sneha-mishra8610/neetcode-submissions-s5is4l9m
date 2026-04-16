class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len=s.length(),n=wordDict.size();
        vector<int> dp(len+1,0);
        dp[0]=1;
        for(int i=0;i<len;i++){
            for(int j=0;j<n;j++){
                string word=wordDict[j];
                int wordLen=word.size();
                if(i-wordLen+1<0)
                continue;
                string trailingString=s.substr(i-wordLen+1,wordLen);
                if(trailingString==word&&dp[i-wordLen+1]>0)
                dp[i+1]=1;
            }
        }
        if(dp[len]==0)
        return false;
        return true;
    }
};