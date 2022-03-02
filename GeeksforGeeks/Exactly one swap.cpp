// There are 2 Approaches to solve this problem

// Approach 1

class Solution
{
public:
    long long countStrings(string S)
    {
        long long umap[26] = {0};
        long long n = S.length();
        long long count = 0;
        int g = 0;
        for (auto c : S)
            umap[c - 97]++;
        int i = 1;
        for (auto c : S)
        {
            if (umap[c - 97] > 1)
                g = 1;
            umap[c - 97] -= 1;
            count += n - i - umap[c - 97];
            i += 1;
        }
        return count + g;
    }
};

// Approach 2

class Solution
{
public:
    long long countStrings(string S)
    {
        long long N = S.size();
        int mp[26] = {0};
        for (auto i : S)
        {
            mp[i - 'a']++;
        }
        long long ans = 0;
        for (auto i : S)
        {
            ans += N - mp[i - 'a'];
        }
        ans /= 2;
        for (int i = 0; i < 26; i++)
        {
            if (mp[i] >= 2)
            {
                ans++;
                break;
            }
        }
        return ans;
    }
};