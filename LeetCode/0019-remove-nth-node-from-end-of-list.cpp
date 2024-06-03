// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void removeNthFromEnd(ListNode** head, int n) {
        ListNode* node = *head;
        int cnt = 0;
        while (cnt++ < n)
        {
            node = node->next;
        }
        while (node)
        {
            head = &(*head)->next;
            node = node->next;
        }
        *head = (*head)->next;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        removeNthFromEnd(&head, n);
        return head;
    }
};