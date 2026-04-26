class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        int n=a.size();
        int x=-1,y=-1,x1=-1,y1=-1;
        for(int i=0;i<n;i++){
            if(b[0]<=a[i][1]&&b[1]>=a[i][0]){
            x=i;
            x1=min(b[0],a[i][0]);
            break;
            }
        }
        if(x==-1){
            a.push_back(b);
            sort(a.begin(),a.end());
            return a;
        }
        for(int i=n-1;i>=x;i--){
            if(b[1]>=a[i][0]){
                y=i;
                y1=max(b[1],a[i][1]);
                break;
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<x;i++)
            ans.push_back(a[i]);
        for(int i=y+1;i<n;i++)
            ans.push_back(a[i]);
        ans.push_back({x1,y1});
        sort(ans.begin(),ans.end());
        return ans;
    }
};