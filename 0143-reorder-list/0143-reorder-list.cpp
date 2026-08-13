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
    ListNode* revList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = revList(slow->next); // rev the 2nd half
        slow->next = NULL;

        while(head != NULL && newHead != NULL) {
            ListNode* front1 = head->next;
            ListNode* front2 = newHead->next;

            head->next = newHead;
            newHead->next = front1;

            newHead = front2;
            head = front1;

        }

    }
};