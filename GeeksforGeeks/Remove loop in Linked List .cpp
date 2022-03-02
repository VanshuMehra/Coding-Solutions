// There are 2 Approaches to solve this problem

// Approach 1

class Solution
{
public:
    Node *solve(Node *meet, Node *head)
    {
        while (head != meet)
        {
            head = head->next;
            meet = meet->next;
        }
        return head;
    }
    void removeLoop(Node *head)
    {
        int isC = 0;
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isC = 1;
                break;
            }
        }
        if (isC != 1)
            return;
        Node *vic = solve(slow, head);
        while (slow->next != vic)
        {
            slow = slow->next;
        }
        slow->next = NULL;
        return;
    }
};

// Approach 2

class Solution
{
public:
    void removeLoop(Node *head)
    {
        if (!head)
            return;

        Node *fast = head->next;
        Node *slow = head;

        while (fast != slow)
        {
            if (!fast || !fast->next)
                return;
            fast = fast->next->next;
            slow = slow->next;
        }

        int size = 1;
        fast = fast->next;

        while (fast != slow)
        {
            size++;
            fast = fast->next;
        }

        slow = head;
        fast = head;

        for (int i = 0; i < size - 1; i++)
            fast = fast->next;
        while (fast->next != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = NULL;
    }
};