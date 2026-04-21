class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        vector<int> t;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                v.push_back(t);
                t.clear();
            }
            else
                t.push_back(nums[i]);
        }
        v.push_back(t);
        int m=0;
        for(int i=0;i<v.size();i++){
            int l=v[i].size();
            int a=1,b=-(10e8+7);
            int p=1;
            for(int j=0;j<l;j++){
                p=v[i][j]*p;
                if(p>0){
                    m=max(m,p/a);
                    a=min(a,p);
                }
                else{
                    m=max(m,p/b);
                    b=max(b,p);
                }
            }
        }
        if(nums.size()==1&&nums[0]<0)
        m=nums[0];
        return m;
    }
};