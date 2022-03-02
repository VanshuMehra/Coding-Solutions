//  There are 3 Appproaches to solve this problem

// Approach 1

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;
        while (left <= right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

//  Approach 2

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

// Approach 3

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int mid = s.size() / 2;
        int end = s.size() - 1;

        for (int i = 0; i < mid; i++)
        {
            char tmp;
            tmp = s[i];
            s[i] = s[end];
            s[end--] = tmp;
        }
    }
};