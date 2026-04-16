class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        vector<int> r(26,0);
        int k=0,n=s.length();
        for(int i=0;i<n;i++){
            int p=(int)s[i]-97;
            v[p]++;
        }
        for(int i=0;i<t.length();i++){
            int p=(int)t[i]-97;
            r[p]++;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=r[i])
            k++;
        }
        if(k==0)
        return(true);
        else
        return(false);
    }
};