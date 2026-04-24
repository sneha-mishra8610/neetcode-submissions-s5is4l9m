class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n=a.size(),m=0;
        stack<int> s;
        a.push_back(0);
        for(int i=0;i<=n;i++){
            while(!s.empty()&&a[i]<=a[s.top()]){
                int h=a[s.top()];
                s.pop();
                int l;
                if(s.empty())
                l=-1;
                else
                l=s.top();
                int wid=i-l-1;
                m=max(m,(wid*h));
            }
            s.push(i);
        }
        return m;
    }
};