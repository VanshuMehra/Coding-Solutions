// There are 2 Approaches to solve this problem

// Approach 1
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &num)
    {
        vector<vector<int>> result;
        sort(num.begin(), num.end());
        do
        {
            result.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        return result;
    }
};

// Approach 2

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(num, path, result);
        return result;
    }

private:
    void dfs(const vector<int> &num, vector<int> &path,
             vector<vector<int>> &result)
    {
        if (path.size() == num.size())
        {
            result.push_back(path);
            return;
        }
        for (auto i : num)
        {
            auto pos = find(path.begin(), path.end(), i);
            if (pos == path.end())
            {
                path.push_back(i);
                dfs(num, path, result);
                path.pop_back();
            }
        }
    }
};
