// There are 2 approaches to solve this problem

// Approach 1

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> temp(num + 1, 0);

        for (int i = 1; i <= num; ++i)
        {
            temp[i] = temp[i & (i - 1)] + 1;
        }

        return temp;
    }
};

// Approach 2

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res;
        for (int i = 0; i <= num; ++i)
        {
            res.push_back(bitset<32>(i).count());
        }
        return res;
    }
};