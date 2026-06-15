class Solution {
public:
    void preorder(TreeNode* root , vector<int>&ans){
        if(root == NULL){
            return;
        }

        preorder(root->left,ans);
        preorder(root->right,ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};
