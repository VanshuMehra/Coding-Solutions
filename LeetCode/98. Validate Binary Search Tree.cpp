class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    bool isValidBST(TreeNode *root, int lower, int upper)
    {
        if (root == nullptr)
            return true;
        return root->val > lower && root->val < upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
};