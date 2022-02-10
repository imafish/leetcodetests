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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *tail = head;
        ListNode *toDel = head;
        for (int i = 0; i < n; i++)
        {
            tail = tail->next;
        }

        if (tail == nullptr)
        {
            return head->next;
        }

        while (tail->next != nullptr)
        {
            tail = tail->next;
            toDel = toDel->next;
        }

        ListNode *next = toDel->next->next;
        toDel->next->next = nullptr;
        toDel->next = next;

        return head;
    }
};
