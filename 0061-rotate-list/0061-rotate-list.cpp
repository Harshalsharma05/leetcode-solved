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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k == 0) return head;
        
        // find length
        int n = 1;
        ListNode* tail = head;
        while(tail->next != NULL) {
            n++;
            tail = tail->next;
        }

        // trim extra k
        k = k % n;
        cout << k;
        if (k == 0) return head;
        
        // make circular
        tail->next = head;

        // find newTail
        int steps = n-k;
        ListNode* newTail = head;

        while(steps > 1) {
            newTail = newTail->next;
            steps -= 1;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};