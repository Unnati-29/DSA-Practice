class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        for(int i=0;i<n;i++){
            while(!s.empty() && heights[i] <= heights[s.top()]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans,currArea);
        }
        return ans;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int column=matrix[0].size();

        vector<int>height(column,0);
        int maxArea=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(matrix[i][j] == '1'){
                    height[j] += 1;
                }
                else{
                    height[j]=0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};
