#include "afx.h"
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        return merge(lists, 0, lists.size());
    }

private:
    ListNode *mergeTwo(ListNode *a, ListNode *b)
    {
        ListNode dummy;
        ListNode *current = &dummy;

        while (a != nullptr && b != nullptr)
        {
            if (a->val < b->val)
            {
                current->next = a;
                current = a;
                a = a->next;
            }
            else
            {
                current->next = b;
                current = b;
                b = b->next;
            }
        }
        if (a == nullptr)
        {
            current->next = b;
        }
        else
        {
            current->next = a;
        }
        return dummy.next;
    }

    ListNode *merge(vector<ListNode *> &lists, int left, int right)
    {
        if (right - left <= 1)
        {
            return lists[left];
        }

        int mid = (left + right) / 2;
        ListNode *lp = merge(lists, left, mid);
        ListNode *rp = merge(lists, mid, right);
        return mergeTwo(lp, rp);
    }
};
