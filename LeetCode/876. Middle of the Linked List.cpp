//  There are 3 Approaches to solve this problem

// Approach 1

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode *> A = {head};
        while (A.back()->next != NULL)
            A.push_back(A.back()->next);
        return A[A.size() / 2];
    }
};

// Approach 2

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Approach 3

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int size = 0;
        auto it = head;
        while (it != NULL)
        {
            size++;
            it = it->next;
        }

        auto it2 = head;
        int target = (size + 1) % 2 == 0 ? (size + 1) / 2 : (size + 1) / 2 + 1;
        int count = 0;
        while (it2 != NULL)
        {
            count++;
            if (count == target)
                return it2;
            it2 = it2->next;
        }

        return it2;
    }
};