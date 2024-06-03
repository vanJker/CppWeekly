#include <vector>
using std::vector;
// https://en.cppreference.com/w/cpp/container/vector

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
    void merge(ListNode** l1, ListNode** l2) {
        ListNode** head = l1;
        ListNode* n1 = *l1, * n2 = *l2;
        while (n1 && n2)
        {
            if (n1->val < n2->val) {
                *head = n1;
                n1 = n1->next;
            }
            else {
                *head = n2;
                n2 = n2->next;
            }
            head = &(*head)->next;
        }
        *head = n1 ? n1 : n2;
        *l2 = nullptr;
    }

    void mergeKLists(vector<ListNode*>& lists, int l, int r) {
        if (r - l <= 1) return;
        int mid = (l + r) / 2;
        mergeKLists(lists, l, mid);
        mergeKLists(lists, mid, r);
        merge(&lists[l], &lists[mid]);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        mergeKLists(lists, 0, lists.size());
        return lists.empty() ? nullptr : lists[0];
    }
};