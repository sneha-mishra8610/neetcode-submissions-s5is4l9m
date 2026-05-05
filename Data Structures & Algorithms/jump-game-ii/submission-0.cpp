class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int m=0,p=0,k=0;
        for(int i=0;i<n-1;i++){
            m=max(m,nums[i]+i);
            if(i==p){
            k++;
            p=m;
            }
        }
        return k;
    }
};