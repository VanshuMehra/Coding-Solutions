class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0)
            return head;
        int len = 1;
        ListNode *p = head;
        while (p->next)
        {
            len++;
            p = p->next;
        }
        k = len - k % len;
        p->next = head;
        for (int step = 0; step < k; step++)
        {
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};