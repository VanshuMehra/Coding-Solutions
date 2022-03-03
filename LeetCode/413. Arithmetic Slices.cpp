// There are 3 approaches to solve this problem

// Approach 1

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int res = 0, i = 0;
        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            const auto start = i;

            while (i + 2 < nums.size() && nums[i + 2] + nums[i] == 2 * nums[i + 1])
            {
                res += (i++) - start + 1;
            }
        }
        return res;
    }
};

// Approach 2

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        if (A.size() < 3)
            return 0;
        vector<int> B(A.size() - 2, 0);
        for (int i = 2; i < A.size(); ++i)
        {
            if (A[i - 1] - A[i - 2] == A[i] - A[i - 1])
                B[i - 2] = 1;
        }
        return all1SubArrays(B);
    }

private:
    int all1SubArrays(const vector<int> &A)
    {
        int sum = 0;
        int curr = 0;
        for (int i = 0; i < A.size(); ++i)
            if (A[i])
                sum += ++curr;
            else
                curr = 0;
        return sum;
    }
};

// Approach 3

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        int sum = 0;
        int curr = 0;
        for (int i = 2; i < A.size(); ++i)
        {
            if (A[i - 1] - A[i - 2] == A[i] - A[i - 1])
            {
                sum += ++curr;
            }
            else
            {
                curr = 0;
            }
        }
        return sum;
    }
};