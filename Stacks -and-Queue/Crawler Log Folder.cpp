class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0,i=0;
        while(i<logs.size()){
            if(logs[i] == "../"){
                if(depth>0){
                    depth--;
                }
            }
            else if(logs[i] == "./"){
               
            }
            else{
                depth++;
            }
            i++;
        }
        return depth;
    }
};
