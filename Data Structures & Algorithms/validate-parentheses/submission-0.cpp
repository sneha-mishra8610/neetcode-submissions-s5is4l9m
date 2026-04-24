class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        map<char,char> mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        bool k=true;
        for(int i=0;i<n;i++){
            char d=s[i];
            if(d=='('||d=='{'||d=='[')
            st.push(d);
            else{
                if(st.empty()||st.top()!=mp[d]){
                    k=false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty())
        k=false;
        return k;
    }
};