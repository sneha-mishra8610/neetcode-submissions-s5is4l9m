class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int s=nums[l]+nums[r];
            if(s==target)
            break;
            else if(s<target)
            l++;
            else
            r--; 
        }
        vector<int> v={l+1,r+1};
        return v;
    }
};