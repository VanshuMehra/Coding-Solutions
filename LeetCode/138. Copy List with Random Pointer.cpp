class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, int> node2id;
        unordered_map<int, Node *> id2node;
        Node *ptr = head;
        int i = 0;
        for (; ptr; ++i, ptr = ptr->next)
        {
            node2id[ptr] = i;
        }
        node2id[ptr] = i;
        Node *dummy = new Node(-1);
        Node *ptr1 = head, *ptr2 = dummy;
        i = 0;
        for (; ptr1 != nullptr; ptr1 = ptr1->next, ptr2 = ptr2->next, ++i)
        {
            ptr2->next = new Node(ptr1->val);
            id2node[i] = ptr2->next;
        }
        id2node[i] = nullptr;
        for (ptr2 = dummy->next, ptr1 = head; ptr1 && ptr2; ptr1 = ptr1->next, ptr2 = ptr2->next)
        {
            int id = node2id[ptr1->random];
            ptr2->random = id2node[id];
        }
        return dummy->next;
    }
};