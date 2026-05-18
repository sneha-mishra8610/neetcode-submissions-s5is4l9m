class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int n=g.size();
        int x=0,ans=0;
        for(int i=0;i<n;i++){
            x+=(g[i]-c[i]);
            if(x<0){
                x=0;
                ans=i+1;
                if(ans==n)
                return -1;
            }
        }
        for(int i=0;i<ans;i++){
            x+=(g[i]-c[i]);
            if(x<0)
            return -1;
        }
        return ans;
    }
};