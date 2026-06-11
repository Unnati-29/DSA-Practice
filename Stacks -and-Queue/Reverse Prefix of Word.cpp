class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char>s;
        int i=0;
        int index=-1;
        while(i<word.size()){
            s.push(word[i]);
            if(word[i] == ch){
                index=i;
                break;
            }
            
            i++;
        }

        if (index == -1){
            return word;
        }
        
        string inter = "";
        while(!s.empty()){
            inter += s.top();
            s.pop();
        }

        string ans = word;
        ans.replace(0,index+1,inter);
        return ans;
    }
};
