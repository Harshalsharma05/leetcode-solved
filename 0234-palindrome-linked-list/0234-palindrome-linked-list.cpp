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

    ListNode* reverseListEasy(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;

        while(temp != NULL) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    // ListNode* reverseList(ListNode* head) {

    //     if(head == NULL || head->next == NULL) return head;

    //     ListNode* newHead = reverseList(head->next);
    //     ListNode* front = head->next; // next node after the curr node to remember
    //     front->next = head;
    //     head->next = NULL;

    //     return newHead;
    // }
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* first = head;
        ListNode* second = reverseListEasy(slow->next); // new head

        while(second != NULL){
            if(first->val != second->val) return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};