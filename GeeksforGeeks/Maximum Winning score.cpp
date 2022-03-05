// There are 2 approaches to solve this problem

// Approach 1

class Solution
{
public:
    long long findMaxScore(Node *root)
    {
        if (root == NULL)
            return 1;
        long long answer1 = findMaxScore(root->left);
        long long answer2 = findMaxScore(root->right);
        return max(root->data * answer1, root->data * answer2);
    }
};

// Approach 2

class Solution
{
public:
    long long getMaxScore(Node *root)
    {
        long long MaxScore = 1;

        if (root == NULL)
            return MaxScore;

        MaxScore = max(MaxScore, getMaxScore(root->left));

        MaxScore = max(MaxScore, getMaxScore(root->right));

        return MaxScore * root->data;
    }

    long long findMaxScore(Node *root)
    {
        long long result = getMaxScore(root);
        return result;
    }
};