class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()) {
            int n = q.size();
            vector<int> level;

            for(int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(!leftToRight) {
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
