class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplet, vector<int>& target) {
        int n=triplet.size(),m1=0,m2=0,m3=0;
        for(int i=0;i<n;i++){
            if(target[0]<triplet[i][0]||target[1]<triplet[i][1]||target[2]<triplet[i][2])
            continue;
            m1=max(m1,triplet[i][0]);
            m2=max(m2,triplet[i][1]);
            m3=max(m3,triplet[i][2]);
        }
        return (m1==target[0]&&m2==target[1]&&m3==target[2]);
    }
};