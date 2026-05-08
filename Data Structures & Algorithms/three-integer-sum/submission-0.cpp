class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i-1]==nums[i])
            continue;
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    vector<int> v={nums[i],nums[l],nums[r]};
                    ans.push_back(v);
                    l++;
                    r--;
                }else if(sum<0)
                    l++;
                else 
                    r--;
            }
        }
        vector<vector<int>> r;
        sort(ans.begin(),ans.end());
        if(ans.size()>0)
        r.push_back(ans[0]);
        for(int i=1;i<ans.size();i++){
            if(ans[i]==ans[i-1])
            continue;
            r.push_back(ans[i]);
        }
        return r;
    }
};