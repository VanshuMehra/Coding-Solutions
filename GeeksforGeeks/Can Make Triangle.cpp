class Solution
{
public:
    vector<int> canMakeTriangle(vector<int> V, int N)
    {
        vector<int> answer;
        for (int i = 0; i + 2 < V.size(); i++)
        {
            int x = V[i];
            int y = V[i + 1];
            int z = V[i + 2];
            if (x + y > z && x + z > y && y + z > x)
                answer.push_back(1);
            else
                answer.push_back(0);
        }
        return answer;
    }
};