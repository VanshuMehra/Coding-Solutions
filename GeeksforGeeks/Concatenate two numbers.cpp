// There are 2 approaches to solve this problem

// Approach 1

class Solution
{
public:
    long long countPairs(int N, int X, vector<int> numbers)
    {
        unordered_map<int, int> suffixMap;
        int n = X, suffix = 0, mul = 1;
        while (n > 0)
        {
            if (n % 10)
            {
                suffix = n % 10 * mul + suffix;
                for (auto num : numbers)
                    suffixMap[suffix] += num == suffix;
            }
            n /= 10;
            mul *= 10;
        }

        int ans = 0;
        mul /= 10;
        while (mul > 0)
        {
            int prefix = X / mul;
            int suffix = X % mul;

            // Don't calculate if suffix starts with 0.
            if (suffix >= mul / 10)
            {
                int prefixCount = 0;
                for (auto num : numbers)
                    prefixCount += num == prefix;

                ans += prefixCount * suffixMap[suffix];
                if (prefix == suffix)
                    ans -= prefixCount;
            }

            mul /= 10;
        }

        return ans;
    }
};

// Approach 2

class Solution
{
public:
    long long countPairs(int N, int X, vector<int> numbers)
    {
        long long ans = 0;
        unordered_map<string, int> mp;
        string tmp = to_string(X);
        for (auto i : numbers)
        {
            mp[to_string(i)]++;
        }
        for (int i = 0; i + 1 < tmp.size(); i++)
        {
            string p = tmp.substr(0, i + 1);
            string q = tmp.substr(i + 1);
            long long f1 = mp[p];
            long long f2 = mp[q];
            if (p == q)
            {

                ans += (f1 * (f1 - 1));
            }
            else
            {
                ans += f1 * f2;
            }
        }

        return ans;
    }
};