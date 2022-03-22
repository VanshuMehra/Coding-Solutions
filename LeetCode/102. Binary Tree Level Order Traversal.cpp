class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> que;

        if (root != nullptr)
        {
            que.emplace(root);
        }
        while (!que.empty())
        {
            vector<int> level;
            int size = que.size();

            for (int i = 0; i < size; i++)
            {
                auto *front = que.front();
                que.pop();
                level.emplace_back(front->val);
                if (front->left != nullptr)
                {
                    que.emplace(front->left);
                }
                if (front->right != nullptr)
                {
                    que.emplace(front->right);
                }
            }
            result.emplace_back(move(level));
        }
        return result;
    }
};