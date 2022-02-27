// There are 2 different ways to solve this problem

// Solution 1

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> ans(n);

        for (int i = 0; i < n; ++i)
        {
            ans[(i + k) % n] = nums[i];
        }

        for (int i = 0; i < n; ++i)
        {
            nums[i] = ans[i];
        }
    }
};

// Solution 2

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;

        int count = 0;

        for (int start = 0; count < n; ++start)
        {
            int cur = start;
            // temporarily store the value k position before nums[next]
            int prev = nums[cur];
            do
            {
                int next = (cur + k) % n;
                // cout << "nums[" << next << "]: " << prev << endl;
                swap(nums[next], prev);
                cur = next;
                ++count;
            } while (cur != start);
        }
    }
};