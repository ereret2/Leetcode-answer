/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// If you have done 92, it will be easier for you to do this problem.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || head == NULL)
            return head;
        ListNode* tmp = head;
        int lenOfList = 0;
        while(tmp != NULL)
        {
            tmp = tmp->next;
            lenOfList++;
        }
        if (k > lenOfList)
            return head;
        int maxM = lenOfList / k;
        int i = 0;
        while (i < maxM)
        {
            int m = i * k + 1, n = (i + 1) * k;
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
            i++;
        }
        
        return head;
    }
};