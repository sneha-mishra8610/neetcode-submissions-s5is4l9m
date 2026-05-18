#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int s=nums[0];
        for(i=1;i<n;i++){
            if(s<i)
                break;
            else
                s=max(s,nums[i]+i);
        }
        if(i==n)
        return(true);
        else
        return(false);
    }
};