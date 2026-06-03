class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            string c=tokens[i];
            if(c.length()==1&&(c=="+"||c=="-"||c=="*"||c=="/")){
                int t=st.top();
                st.pop();
                int s=st.top();
                st.pop();
                if(c=="+")
                    st.push(s+t);
                else if(c=="-")
                st.push(s-t);
                else if(c=="*")
                st.push(s*t);
                else if(c=="/")
                st.push(s/t);
            }
                else if(c[0]=='-')
                st.push(-1*stoi(c.substr(1,c.length()-1)));
                else
                st.push(stoi(c));
        }
        return st.top();
    }
};