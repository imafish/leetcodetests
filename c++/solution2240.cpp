#include "afx.h"
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *next = nullptr;
        ListNode *reversed = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = reversed;
            reversed = current;
            current = next;
        }

        return reversed;
    }
};

/*
[ ] -> [ ] -> [ ] -> nullptr
 ^      ^
 c      n

*/
