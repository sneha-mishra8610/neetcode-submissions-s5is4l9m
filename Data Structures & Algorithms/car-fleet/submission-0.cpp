class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        int n=p.size();
        stack<double> st;
        vector<pair<int,int>> k(n);
        for(int i=0;i<n;i++)
        k[i]={p[i],s[i]};
        sort(k.begin(),k.end());
        for(int i=0;i<n;i++){
            double v=(double(t)-double(k[i].first))/(double)(k[i].second);
            st.push(v);
        }
        stack<double> ans;
        ans.push(st.top());
        st.pop();
        while(!st.empty()){
            double d=st.top();
            st.pop();
            if(ans.top()<d)
            ans.push(d);
        }
        return ans.size();
    }
};