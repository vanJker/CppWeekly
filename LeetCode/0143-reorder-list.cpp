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
    void reverseList(ListNode** head) {
        ListNode* prev = nullptr, *next;
        while (*head)
        {
            next = (*head)->next;
            (*head)->next = prev;
            prev = (*head);
            *head = next;
        }
        *head = prev;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head, *prev;
        while (fast && fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = nullptr;
        return slow;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* mid = middleNode(head);
        reverseList(&mid);
        ListNode* next, **p = &head;
        while (head && mid)
        {
            next = head->next;
            head->next = mid;
            *p = head;
            p = &mid->next;
            head = next;
            mid = mid->next;
        }
        *p = head ? head : mid;
    }
};