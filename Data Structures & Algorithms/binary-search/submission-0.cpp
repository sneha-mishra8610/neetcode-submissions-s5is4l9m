#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target))
        {
            auto ind=lower_bound(nums.begin(),nums.end(),target);
            int index=ind-nums.begin();
            return(index);
        }
        else
        return(-1);
    }
};