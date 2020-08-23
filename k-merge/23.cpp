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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        priority_queue<ListNode*, vector<ListNode*>, cmp> p;
        
        for (int i = 0; i < k; i++)
        {
            if (lists[i])
            {
                p.push(lists[i]);
            }
        }
        if (p.empty())
            return NULL;
        while (!p.empty())
        {
            ListNode* tmp = p.top();
            p.pop();
            curr->next = tmp;
            curr = curr->next;
            // cout << curr->val << endl;
            if (tmp->next)
            {
                p.push(tmp->next);
            }
        }
        return res->next;
    }

    struct cmp
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };
};