// LeetCode 1021 - Remove Outermost Parentheses
// Topic: String
// Difficulty: Easy
// Time Complexity: O(n)

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";
        for(int i = 0;i<s.length();i++){
            if(s[i] == '('){
                if(count > 0){
                    ans += '(';
                }
                count ++;
            }
            else{
                count--;
                if(count > 0){
                    ans += ')';
                }
            }
        }
        return ans;
    }
};
