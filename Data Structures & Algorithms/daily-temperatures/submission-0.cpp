class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> ans(n);
        stack<pair<int,int>> st;
        st.push({t[0],0});
        for(int i=1;i<n;i++){
                while(!st.empty()&&st.top().first<t[i]){
                    int index=st.top().second,val=st.top().first;
                    st.pop();
                    ans[index]=i-index;
                }
            st.push({t[i],i});
        }
        while(!st.empty()){
            int index=st.top().second;
            ans[index]=0;
            st.pop();
        }
        return ans;
    }
};