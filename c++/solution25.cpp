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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy;
        dummy.next = head;
        ListNode *start = &dummy;
        ListNode *end = nullptr;
        while ((end = findNext(start, k)) != nullptr)
        {
            ListNode *next = start->next;
            swapNodes(start, end);
            start = next;
        }

        return dummy.next;
    }

private:
    inline ListNode *findNext(ListNode *start, int k)
    {
        while (start != nullptr && k-- > 0)
        {
            start = start->next;
        }
        return start;
    }

    inline void swapNodes(ListNode *start, ListNode *end)
    {
        ListNode *current = start->next;
        ListNode *done = end->next;
        while (current->next != done)
        {
            ListNode *toMove = current->next;
            current->next = toMove->next;
            toMove->next = start->next;
            start->next = toMove;
        }
    }
};

int main()
{
    ListNode nodes[5];
    for (int i = 0; i < 5; i++)
    {
        nodes[i].val = i + 1;
        if (i + 1 < 5)
        {
            nodes[i].next = nodes + i + 1;
        }
    }

    Solution s;
    s.reverseKGroup(nodes, 2);
}
