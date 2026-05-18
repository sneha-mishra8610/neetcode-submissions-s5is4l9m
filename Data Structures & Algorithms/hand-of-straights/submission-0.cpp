class Solution {
public:
    bool isNStraightHand(vector<int>& a, int g) {
        int n=a.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[a[i]]++;
        vector<pair<int,int>> m;
        for(auto u:mp)
            m.push_back(u);
        sort(m.begin(),m.end());
        for(int i=0;i<m.size();i++){
            if(m[i].second>0){
                int p=m[i].second;
                for(int j=0;j<g;j++){
                    if(i+j>=m.size())
                    return false;
                    if(m[i+j].second<p||m[i+j].first-m[i].first!=j)
                    return false;
                    else
                    m[i+j].second-=p;
                }
            }
        }
        for(int i=0;i<m.size();i++){
            if(m[i].second!=0)
            return false;
        }
        return true;
    }
};