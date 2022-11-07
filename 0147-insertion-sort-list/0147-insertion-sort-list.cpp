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
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        int temp = 0;
        for (ListNode * current = head;  current != nullptr;  current = current->next)
        {
            for (ListNode *prev = head; prev !=  current; prev = prev->next)
            {
                if ( current->val < prev->val)
                {
                    swap(current->val,prev->val);
                }
            }
        }
        return head;
    }
};