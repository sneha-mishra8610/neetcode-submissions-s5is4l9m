class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,ans=min(height[l],height[r])*(r-l);
        while(l<r){
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r])
            l++;
            else if(height[l]>height[r])
            r--;
            else{
                l++;
                r--;
            }
        }
        return ans;
    }
};