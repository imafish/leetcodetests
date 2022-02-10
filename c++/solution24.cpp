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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *current = dummy;
        while (current->next != nullptr && current->next->next != nullptr)
        {
            ListNode *first = current->next;
            ListNode *second = first->next;
            ListNode *third = second->next;

            current->next = second;
            first->next = third;
            second->next = first;

            current = first;
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};
