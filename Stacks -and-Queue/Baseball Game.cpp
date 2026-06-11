class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>record;
        int i = 0;
        while(i<operations.size()){
            if(operations[i] == "D"){
                record.push(record.top()*2);
            }else if(operations[i] == "C"){
                record.pop();
            }else if(operations[i] == "+"){
                int first=record.top();
                record.pop();
                int second=record.top();
                record.push(first);
                record.push(first+second);
            }else{
                record.push(stoi(operations[i]));
            }
            i++;
        }
        int sum = 0;
        while(!record.empty()){
            sum += record.top();
            record.pop();
        }
        return sum;
    }
};
