class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int row = image.size();
            int column = image[0].size();
            int original = image[sr][sc];

            if(original == color){
                return image;
            }

            queue<pair<int,int>> q;
            q.push({sr, sc});
            image[sr][sc] = color;

            while(q.size()>0){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i-1 >= 0 && image[i-1][j] == original){
                    q.push({i-1,j});
                    image[i-1][j] = color;
                }

                if(j+1 < column & image[i][j+1] == original){
                    q.push({i,j+1});
                    image[i][j+1] = color;
                }

                if(i+1 < row && image[i+1][j] == original){
                    q.push({i+1,j});
                    image[i+1][j] = color;
                }

                if(j-1 >= 0 && image[i][j-1] == original){
                    q.push({i,j-1});
                    image[i][j-1] = color;
                }
            }
        return image;
    }
};
