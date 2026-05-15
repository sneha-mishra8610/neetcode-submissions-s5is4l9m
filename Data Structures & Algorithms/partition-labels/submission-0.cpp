class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> freq(26,0);
        vector<int> open(26,0);
        int opened=0,last=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            freq[idx]++;
        }
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(open[idx]==0)
            opened++;
            open[idx]++;
            if(open[idx]==freq[idx])
            opened--;
            if(opened==0){
            ans.push_back(i-last+1);
            last=i+1;
            }
        }
        return ans;
    }
};