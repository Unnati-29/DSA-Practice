class Solution {
public:
    int depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);

        return (1+max(right,left));
    }

    int maxDepth(TreeNode* root) {
       return depth(root);
    }
};
