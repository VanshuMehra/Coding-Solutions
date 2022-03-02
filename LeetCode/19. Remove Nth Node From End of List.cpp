// There are 3 Approaches to solve this problem

// Approach 1

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy{-1, head};
        ListNode *p = &dummy, *q = &dummy;
        for (int i = 0; i < n; i++)
            q = q->next;
        while (q->next)
        {
            p = p->next;
            q = q->next;
        }
        ListNode *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return dummy.next;
    }
};

// Approach 2

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast;
        ListNode *slow;

        fast = head;
        slow = head;

        while (n)
        {
            fast = fast->next;
            n--;
        }

        if (fast == NULL)
        {
            head = head->next;
            return head;
        }

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        if (slow->next && slow->next->next)
        {
            slow->next = slow->next->next;
        }
        else
        {
            slow->next = NULL;
        }

        return head;
    }
};

// Approach 3

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        auto it = head;
        int size = 0;
        while (it != NULL)
        {
            size++;
            it = it->next;
        }

        if (size == 1)
        {
            head = NULL;
            return head;
        }
        else if (size == n)
        {
            head = head->next;
            return head;
        }
        else if (size - 1 == n)
        {
            cout << size << endl;
            head->next = head->next->next;
            return head;
        }

        int target = size - n + 1;
        auto cur = head->next, prev = head;
        int count = 2;
        while (cur != NULL)
        {
            prev = cur;
            cur = cur->next;
            count++;
            if (count == target)
            {
                cur = cur->next;
                prev->next = cur;
            }
        }

        return head;
    }
};