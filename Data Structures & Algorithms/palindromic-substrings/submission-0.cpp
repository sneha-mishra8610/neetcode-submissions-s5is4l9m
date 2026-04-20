class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=1;j+i<=n;j++){
                string w=s.substr(i,j);
                string p=w;
                reverse(w.begin(),w.end());
                if(w==p)
                ans++;
            }
        }
        return ans;
    }
};