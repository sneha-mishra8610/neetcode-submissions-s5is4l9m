class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string w="",m="";
        bool k=true;
        int left=0,right=n-1;
        while(left<=right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            char c=s[left];
            char d=s[right];
            if((int)c>=65&&(int)c<=90)
            c=(char)((int)s[left]+32);
            if((int)d>=65&&(int)d<=90)
            d=(char)((int)s[right]+32);
            if(c!=d)
            k=false;
            left++;
            right--;
        }
        return(k);
    }
};