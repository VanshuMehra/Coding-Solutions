// There are 2 Approaches to solve this problem

// Approach 1

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(0);
        auto it1 = l1, it2 = l2;
        auto it3 = ans;

        while (it1 != NULL && it2 != NULL)
        {
            if (it1->val <= it2->val)
            {

                it3->next = it1;
                it1 = it1->next;
            }
            else
            {
                it3->next = it2;
                it2 = it2->next;
            }
            it3 = it3->next;
        }
        while (it1 != NULL)
        {
            it3->next = it1;
            it1 = it1->next;
            it3 = it3->next;
        }
        while (it2 != NULL)
        {
            it3->next = it2;
            it2 = it2->next;
            it3 = it3->next;
        }

        return ans->next;
    }
};

// Approach 2

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *result = nullptr;
        ListNode *nextResultNode = nullptr;
        ListNode *nextNode = nullptr;

        while (true)
        {
            if (l1 == nullptr && l2 == nullptr)
            {
                break;
            }
            else if (l1 != nullptr && l2 != nullptr)
            {
                if (l1->val <= l2->val)
                {
                    nextNode = l1;
                    l1 = l1->next;
                }
                else
                {
                    nextNode = l2;
                    l2 = l2->next;
                }
            }
            else if (l1 == nullptr && l2 != nullptr)
            {
                nextNode = l2;
                l2 = l2->next;
            }
            else
            {
                nextNode = l1;
                l1 = l1->next;
            }

            if (nextNode != nullptr)
            {
                if (result == nullptr)
                {
                    result = nextNode;
                    nextResultNode = result;
                }
                else
                {
                    nextResultNode->next = nextNode;
                    nextResultNode = nextResultNode->next;
                }
            }
            else
            {
                break;
            }
        }

        return result;
    }
};