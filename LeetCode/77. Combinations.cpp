// There are 2 Approaches to solve this problem

// Approach 1

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> path;
        dfs(n, k, 1, 0, path, result);
        return result;
    }

private:
    static void dfs(int n, int k, int start, int cur,
                    vector<int> &path, vector<vector<int>> &result)
    {
        if (cur == k)
        {
            result.push_back(path);
        }
        for (int i = start; i <= n; ++i)
        {
            path.push_back(i);
            dfs(n, k, i + 1, cur + 1, path, result);
            path.pop_back();
        }
    }
};

// Approach 2

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> values(n);
        iota(values.begin(), values.end(), 1);
        vector<bool> select(n, false);
        fill_n(select.begin(), k, true);
        vector<vector<int>> result;
        do
        {
            vector<int> one(k);
            for (int i = 0, index = 0; i < n; ++i)
                if (select[i])
                    one[index++] = values[i];
            result.push_back(one);
        } while (prev_permutation(select.begin(), select.end()));
        return result;
    }
};