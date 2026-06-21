class Solution {
public:
vector<vector<int>> ans;
    void combine(vector<int>& v,int target,vector<int> temp,int i){
        if(i==v.size()){
            if(target==0)
            ans.push_back(temp);
            return;
        }
        if(v[i]<=target){
            temp.push_back(v[i]);
            combine(v,target-v[i],temp,i);
            temp.pop_back();
        }
        combine(v,target,temp,i+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        int n=v.size();
        vector<int> temp;
        combine(v,target,temp,0);
        return ans;
    }
};