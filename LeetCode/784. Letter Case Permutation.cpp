class Solution
{
public:
    void backTracking(std::string S, int index, std::vector<std::string> &items)
    {
        if (index >= S.size())
        {
            items.push_back(S);
            return;
        }

        backTracking(S, index + 1, items);

        if ('a' <= S[index] && S[index] <= 'z')
        {
            S[index] -= 32;
            backTracking(S, index + 1, items);
        }
        else if ('A' <= S[index] && S[index] <= 'Z')
        {
            S[index] += 32;
            backTracking(S, index + 1, items);
        }
    }

    vector<string> letterCasePermutation(string S)
    {
        std::vector<std::string> res;
        backTracking(S, 0, res);
        return res;
    }
};