#include "afx.h"

using namespace std;

/*
// Definition for a Node.
*/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        unordered_map<Node *, int> records;
        vector<int> randomRecords;
        vector<Node *> newRecords;

        Node *current = head;
        Node *dummy = new Node(0);
        Node *currentCopy = dummy;
        int index = 0;
        while (current != nullptr)
        {
            currentCopy->next = new Node(current->val);

            records[current] = index;
            newRecords.push_back(currentCopy->next);
            index++;

            current = current->next;
            currentCopy = currentCopy->next;
        }

        current = head;
        while (current != nullptr)
        {
            auto p = current->random;
            if (p == nullptr)
            {
                randomRecords.push_back(-1);
            }
            else
            {
                randomRecords.push_back(records[current->random]);
            }
            current = current->next;
        }

        int i = 0;
        for (auto p = dummy->next; p != nullptr; p = p->next)
        {
            int randomIndex = randomRecords[i++];
            if (randomIndex == -1)
            {
                p->random = nullptr;
            }
            else
            {
                p->random = newRecords[randomIndex];
            }
        }

        auto result = dummy->next;
        delete dummy;

        return result;
    }
};
