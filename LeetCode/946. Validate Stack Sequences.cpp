class Solution
{
public:
    bool validateStackSequences(vector<int> &A, vector<int> &B)
    {
        int j = 0;
        stack<int> s;
        for (int i = 0; i < A.size(); i++)
        {
            s.push(A[i]);
            if (s.top() == B[j])
            {
                while (!s.empty() && j < B.size() && s.top() == B[j])
                {
                    s.pop();
                    j++;
                }
            }
        }
        return s.empty() ? true : false;
    }
};