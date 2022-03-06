// There are 4 approaches to solve this problem

// Approach 1

class Solution
{
public:
    int countOrders(int n)
    {
        long ans = 1;
        int mod = 1e9 + 7;

        for (int i = 1; i <= n; ++i)
        {
            ans = ans * i;
            ans = ans * (2 * i - 1);
            ans %= mod;
        }

        return ans;
    }
};

// Approach 2

class Solution
{
private:
    int mod = 1e9 + 7;
    vector<vector<int>> memo;

    long totalWays(int unpicked, int undelivered)
    {
        if (unpicked == 0 && undelivered == 0)
        {
            return 1;
        }

        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked)
        {
            return 0;
        }

        if (memo[unpicked][undelivered])
        {
            return memo[unpicked][undelivered];
        }

        long ans = 0;
        ans += unpicked * totalWays(unpicked - 1, undelivered);
        ans %= mod;
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
        ans %= mod;

        return memo[unpicked][undelivered] = ans;
    }

public:
    int countOrders(int n)
    {
        memo = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return totalWays(n, n);
    }
};

// Approach 3

class Solution
{
public:
    int mod = 1e9 + 7;

    int countOrders(int n)
    {
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));

        for (int unpicked = 0; unpicked <= n; unpicked++)
        {
            for (int undelivered = unpicked; undelivered <= n; undelivered++)
            {
                if (unpicked == 0 && undelivered == 0)
                {
                    dp[unpicked][undelivered] = 1;
                    continue;
                }

                if (unpicked > 0)
                {
                    dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];
                }
                dp[unpicked][undelivered] %= mod;

                if (undelivered > unpicked)
                {
                    dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];
                }
                dp[unpicked][undelivered] %= mod;
            }
        }

        return dp[n][n];
    }
};

// Approach 4

class Solution
{
public:
    int countOrders(int n)
    {
        long ans = 1;
        int mod = 1e9 + 7;

        for (int i = 1; i <= 2 * n; ++i)
        {
            ans = ans * i;

            if (i % 2 == 0)
            {
                ans = ans / 2;
            }
            ans %= mod;
        }
        return ans;
    }
};