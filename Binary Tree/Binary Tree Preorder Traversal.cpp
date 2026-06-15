class Solution {
public:
    void preorder(TreeNode* root , vector<int> &output){
        if(root == NULL){
            return;
        }
        output.push_back(root->val);
        preorder(root->left, output);
        preorder(root->right, output);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        preorder(root,output);
        return output;
    }
};
