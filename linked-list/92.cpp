/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) 
            return head;

        ListNode* curr = head, *prev = NULL;//find m and the node previous to m.
        int k = 1;
        while (curr != NULL && k != m)
        {
            prev = curr;
            curr = curr->next;
            k++;
        }

        ListNode *endNodeBeforeReverse = prev;
        prev = NULL;
        ListNode *endOfReversal = curr;
        ListNode *next = NULL;
        while (k <= n && curr != NULL)// reverse the linked list between m and n.
        {                                          // the time to finish is when the prevNode is n
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k++;
        }
        if (endNodeBeforeReverse== NULL)
            head = prev;
        else
            endNodeBeforeReverse->next = prev;
        endOfReversal->next = curr;
        return head;
    }
};