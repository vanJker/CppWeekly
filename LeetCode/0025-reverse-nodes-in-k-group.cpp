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
    void reverseK(ListNode** head, int k) {
        if (k <= 1) return;
        ListNode* prev = nullptr, * next, * node = *head;
        while (k--)
        {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        (*head)->next = node;
        *head = prev;
    }

    void reverseKGroup(ListNode** head, int k) {
        ListNode* node = *head;
        int cnt = 0;
        while (node)
        {
            auto safe = node->next;
            if (++cnt == k) {
                auto temp = &(*head)->next;
                reverseK(head, k);
                head = temp;
                cnt = 0;
            }
            node = safe;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        reverseKGroup(&head, k);
        return head;
    }
};