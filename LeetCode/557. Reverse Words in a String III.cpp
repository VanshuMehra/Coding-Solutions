//  There are 3 Approaches to solve this problem

// Approach 1

class Solution
{
public:
    string reverseWords(string s)
    {
        auto size = s.size();
        int from = 0;
        for (int i = 1; i < size; ++i)
        {
            if (s[i] == ' ')
            {
                reverse(begin(s) + from, begin(s) + i);
                from = i + 1;
            }
        }
        reverse(begin(s) + from, end(s));
        return s;
    }
};

// Approach 2

class Solution
{
public:
    string reverse(string s)
    {
        if (s.empty())
            return s;
        string res = "";
        while (!s.empty())
        {
            res += s.back();
            s.pop_back();
        }
        return res;
    }
    vector<string> split(string s)
    {
        vector<string> res;
        if (s.empty())
            return res;
        string temp = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
            {
                res.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }
        if (!temp.empty())
            res.push_back(temp);
        return res;
    }
    string reverseWords(string s)
    {
        vector<string> ss = split(s);
        string res = "";
        for (auto &s : ss)
        {
            res += reverse(s);
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};

// Approach 3

class Solution
{
public:
    void swap_str(string &s, int start, int end)
    {
        int left = start, right = end;
        while (left <= right)
        {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }

    string reverseWords(string s)
    {
        if (s.size() == 1)
            return s;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            { // stop
                swap_str(s, start, i - 1);
                start = i + 1;
            }
            else if (i == s.size() - 1)
            {
                swap_str(s, start, i);
            }
        }

        return s;
    }
};