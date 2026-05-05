class Solution {
public:
    int maxSubArray(vector<int>& v) {
    vector <int> p(v.size()+1);
    p[0]=0;
    for(int i=0;i<v.size();i++) 
        p[i+1]=p[i]+v[i];
    int m=p[0],r=p[1]-m;
    for(int i=1;i<p.size();i++) {
        r=max(r,p[i]-m);
        m=min(m,p[i]);
    }
    return r;
    }
};