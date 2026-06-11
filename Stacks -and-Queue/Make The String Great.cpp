class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int i = 0;
        while(i<s.size()){
            if(!st.empty() && abs(st.top() - s[i]) == 32){
                st.pop();
            }else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
