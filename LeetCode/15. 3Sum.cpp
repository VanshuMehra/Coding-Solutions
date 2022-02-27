// There are 2 ways to solve this problem

// Solution 1

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        const int target = 0;
        auto last = nums.end();
        for (auto i = nums.begin(); i < last - 2; ++i)
        {
            auto j = i + 1;
            if (i > nums.begin() && *i == *(i - 1))
                continue;
            auto k = last - 1;
            while (j < k)
            {
                if (*i + *j + *k < target)
                {
                    ++j;
                    while (*j == *(j - 1) && j < k)
                        ++j;
                }
                else if (*i + *j + *k > target)
                {
                    --k;
                    while (*k == *(k + 1) && j < k)
                        --k;
                }
                else
                {
                    result.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while (*j == *(j - 1) && *k == *(k + 1) && j < k)
                        ++j;
                }
            }
        }
        return result;
    }
};

// Solution 2

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        const int target = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                for (int j = i + 1, k = nums.size() - 1; j < k;)
                {
                    if (j - 1 > i && nums[j] == nums[j - 1])
                    {
                        ++j;
                    }
                    else if (k + 1 < nums.size() && nums[k] == nums[k + 1])
                    {
                        --k;
                    }
                    else
                    {
                        const auto sum = nums[i] + nums[j] + nums[k];
                        if (sum > target)
                        {
                            --k;
                        }
                        else if (sum < target)
                        {
                            ++j;
                        }
                        else
                        {
                            ans.push_back({nums[i], nums[j], nums[k]});
                            ++j, --k;
                        }
                    }
                }
            }
        }
        return ans;
    }
};