class Solution {
public:
    void preorder(TreeNode* root , vector<int>&ans){
        if(root == NULL){
            return;
        }

        preorder(root->left,ans);
        ans.push_back(root->val);
        preorder(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};
