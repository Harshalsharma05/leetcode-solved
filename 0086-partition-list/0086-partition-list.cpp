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
    ListNode* partition(ListNode* head, int x) {
        ListNode* slist = new ListNode(-1);
        ListNode* blist = new ListNode(-1);

        ListNode* s = slist;
        ListNode* b = blist;

        ListNode* tmp = head;

        while(tmp != NULL) {
            ListNode* nextNode = tmp->next; // saving next node to we can point curr (tmp) node to small or big lists
            if(tmp->val < x) {
                s->next = tmp;
                s = s->next;
            } else {
                b->next = tmp;
                b = b->next;
            }
            tmp = nextNode;
        }
        b->next = nullptr;
        // connect small with big list
        s->next = blist->next;
        return slist->next;
    }
};