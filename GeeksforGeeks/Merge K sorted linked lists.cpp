// There are 2 Approaches to solve this problem

// Approach 1

class Solution
{
public:
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < K; i++)
        {
            while (arr[i] != NULL)
            {
                pq.push(arr[i]->data);
                arr[i] = arr[i]->next;
            }
        }

        Node *ans = new Node(pq.top());
        pq.pop();
        Node *curr = ans;

        while (!pq.empty())
        {
            Node *temp = new Node(pq.top());
            curr->next = temp;
            curr = temp;
            pq.pop();
        }

        return ans;
    }
};

// Approach 2

class Solution
{
public:
    Node *SortedMerge(Node *a, Node *b)
    {
        Node *result = NULL;

        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        if (a->data <= b->data)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return result;
    }
    Node *mergeKLists(Node *arr[], int K)
    {
        int N = K;
        int last = N - 1;
        while (last != 0)
        {
            int i = 0, j = last;
            while (i < j)
            {
                arr[i] = SortedMerge(arr[i], arr[j]);

                i++, j--;

                if (i >= j)
                    last = j;
            }
        }
        return arr[0];
    }
};