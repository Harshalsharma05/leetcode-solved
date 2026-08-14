/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* revList(ListNode* curr, ListNode* end) {
        ListNode* prev = NULL;
        ListNode* front = NULL;

        while(curr != end) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;

        ListNode* tail = head;
        for(int i = 0; i < k; ++i) {
            if(!tail) return head;
            tail = tail->next;
        }

        ListNode* newH = revList(head, tail);
        head->next = reverseKGroup(tail, k);

        return newH;
        
    }
};