class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        int l=0,r=n-1;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        while(l<r){
            int sum=v[l].first+v[r].first;
            if(sum==target){
                ans={v[l].second,v[r].second};
                sort(ans.begin(), ans.end());
                return ans;
            }
            else if(sum>target)
            r--;
            else
            l++;
        }
        ans={-1,-1};
        sort(ans.begin(),ans.end());
        return ans;
    }
};